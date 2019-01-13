/*
    Author: Adrian Unkeles
    Project: CabSense Application
    Course: ECEN 5023 (Low Power Design)
    Semester: Fall 2018
 */

package cabsense.cabsenseapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;


import android.support.v4.content.ContextCompat;
import android.support.v4.app.ActivityCompat;
import android.content.pm.PackageManager;
import android.widget.TextView;

import java.io.IOException;
import java.lang.annotation.Target;
import java.util.List;
import java.util.Locale;
import java.util.Timer;
import java.lang.Double;
import java.lang.Float;
import java.lang.Byte;
import java.lang.String;

import android.app.ListActivity;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.ContentResolver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.widget.BaseAdapter;
import android.text.TextUtils;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.UUID;
import android.os.ParcelUuid;
import android.os.Vibrator;

import android.os.Handler;
import android.bluetooth.BluetoothProfile;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.le.BluetoothLeScanner;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanFilter;
import android.bluetooth.le.ScanResult;
import android.bluetooth.le.ScanSettings;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothGattCharacteristic;


public class CabSense_Activity extends AppCompatActivity implements OnClickListener {

    private final int REQUEST_PERMISSION_ACCESS_FINE_LOCATION = 1;
    private LocationManager locationManager = null;
    private LocationListener locationListener = null;

    private Button mDiscoverButton = null;
    private Button mWriteButton = null;
    private EditText editLocation = null;
    private TextView connText = null;
    private TextView mText = null;

    private Context mContext;
    private Vibrator vib;
    private Handler mHandler = new Handler();
    private BluetoothLeScanner mBluetoothLeScanner;
    private BluetoothGatt mBluetoothGatt;
    private BluetoothDevice mDevice;
    private BluetoothAdapter mBluetoothAdapter;
    private BluetoothGattCharacteristic mBluetoothGattCharacteristicLoc;
    private BluetoothGattCharacteristic mBluetoothGattCharacteristicStat;

    private static final String TAG = "Debug";
    private Boolean flag = false;
    private Boolean charWrite = false;

    private Double doubleLon;
    private Double doubleLat;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cab_sense);

        //if you want to lock screen for always Portrait mode
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);

        // interface components (textboxes and buttons)
        editLocation = (EditText) findViewById(R.id.editTextLocation);
        mText = (TextView) findViewById(R.id.text);
        connText = (TextView) findViewById(R.id.connectionTextLocation);
        mDiscoverButton = (Button) findViewById(R.id.discover_btn);
        mDiscoverButton.setOnClickListener(this);
        mWriteButton = (Button) findViewById(R.id.write_btn);
        mWriteButton.setOnClickListener(this);

        locationManager = (LocationManager) getSystemService(Context.LOCATION_SERVICE);

        mContext = getBaseContext();

        // Initializes Bluetooth adapter.
        final BluetoothManager mBluetoothManager = (BluetoothManager) getSystemService(Context.BLUETOOTH_SERVICE);
        mBluetoothAdapter = mBluetoothManager.getAdapter();
        mBluetoothLeScanner = mBluetoothAdapter.getBluetoothLeScanner();

        vib = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);

        flag = displayGpsStatus();
        if (flag) {

            Log.v(TAG, "onClick");

            editLocation.setText("Please move your device to"+
                    " see the changes in coordinates."+"\nWait..", TextView.BufferType.EDITABLE);

            connText.setText("App initialized", TextView.BufferType.EDITABLE);

            locationListener = new CabSense_Activity.MyLocationListener();

            // request Android Bluetooth location permissions if not found
            if ( ContextCompat.checkSelfPermission( this, android.Manifest.permission.ACCESS_FINE_LOCATION ) != PackageManager.PERMISSION_GRANTED ) {

                ActivityCompat.requestPermissions( this, new String[] {  android.Manifest.permission.ACCESS_FINE_LOCATION  },
                        REQUEST_PERMISSION_ACCESS_FINE_LOCATION );
            }

            //request updates every 2[s], with a minimum distance resolution of 1[m]
            locationManager.requestLocationUpdates(LocationManager
                    .GPS_PROVIDER, 2000, 1,locationListener);

        } else {
            mText.setText("GPS Status is OFF");
        }
    }

    // calls to enable UI writes in callback methods (different threads from original Context)
    private void setConnText(final String text)
    {
        mHandler.post(new Runnable(){
            @Override
            public void run() {
                connText.setText(text);
            }
        });
    }

    private void setMText(final String text)
    {
        mHandler.post(new Runnable(){
            @Override
            public void run() {
                mText.setText(text);
            }
        });
    }

    // main callback for GATT-related function calls
    private BluetoothGattCallback mBluetoothGattCallback = new BluetoothGattCallback() {
        @Override
        public void onConnectionStateChange(BluetoothGatt gatt, int status, int newState) {
            super.onConnectionStateChange(gatt, status, newState);

            Log.i("onConnectionStateChange", "Status: " + status);
            switch (newState) {
                case BluetoothProfile.STATE_CONNECTED:
                    Log.e("gattCallback", "connected to device!");
                    setConnText("Connected");
                    gatt.discoverServices();
                    break;
                case BluetoothProfile.STATE_DISCONNECTED:
                    //mBluetoothGatt.disconnect();
                    Log.e("gattCallback", "STATE_DISCONNECTED");
                    Log.i("gattCallback", "reconnecting...");
                    setConnText("Disconnected");
                    BluetoothDevice mDevice = gatt.getDevice();
                    mBluetoothGatt = null;
                    mBluetoothGatt = mDevice.connectGatt(mContext, true, mBluetoothGattCallback, BluetoothDevice.TRANSPORT_LE);
                    break;
                default:
                    Log.e("gattCallback", "STATE_OTHER");
                    break;
            }
        }

        // callback for the app having discovered services on the CabSense Server
        @Override
        public void onServicesDiscovered(BluetoothGatt gatt, int status) {
            super.onServicesDiscovered(gatt, status);

            mBluetoothGatt = gatt;
            BluetoothGattService mBluetoothGattLocService, mBluetoothGattCabService;
            if(status == mBluetoothGatt.GATT_SUCCESS)
            {
                mBluetoothGattLocService = mBluetoothGatt.getService(UUID.fromString(getString(R.string.locationAndServices_uuid)));
                mBluetoothGattCabService = mBluetoothGatt.getService(UUID.fromString(getString(R.string.cabsense_service_uuid)));
                if (mBluetoothGattLocService != null && mBluetoothGattCabService != null) {
                    Log.i(TAG, "Service characteristic UUID found: " + mBluetoothGattLocService.getUuid().toString());
                    Log.i(TAG, "Service characteristic UUID found: " + mBluetoothGattCabService.getUuid().toString());
                } else {
                    Log.i(TAG, "Service characteristic not found for UUID: " + UUID.fromString(getString(R.string.locationAndServices_uuid)));
                    Log.i(TAG, "Service characteristic not found for UUID: " + UUID.fromString(getString(R.string.cabsense_service_uuid)));
                }
            }
            else
                return;

            List<BluetoothGattService> services = mBluetoothGatt.getServices();
            Log.i("onServicesDiscovered", services.toString());
            setConnText("Connected\nServices discovered");

            mBluetoothGattCharacteristicStat = mBluetoothGattCabService.getCharacteristic(UUID.fromString(getString(R.string.cabsense_notifications_uuid)));

            // enable characteristic notifications locally before doing so remotely
            boolean charStat = gatt.setCharacteristicNotification(mBluetoothGattCharacteristicStat, true);

            if(charStat == true)
               Log.i(TAG, "successfully enabled notifications locally");

            //List<BluetoothGattDescriptor> mDescriptor = mBluetoothGattCharacteristicStat.getDescriptors();
            for (BluetoothGattDescriptor descriptor : mBluetoothGattCharacteristicStat.getDescriptors()) {
                descriptor.setValue( BluetoothGattDescriptor.ENABLE_NOTIFICATION_VALUE);
                boolean descStat = mBluetoothGatt.writeDescriptor(descriptor);
                if(descStat == true)
                    Log.i(TAG, "successfully wrote descriptor");
            }

            //List<BluetoothGattCharacteristic> mGattChars = mBluetoothGattService.getCharacteristics();
            mBluetoothGattCharacteristicLoc = mBluetoothGattLocService.getCharacteristic(UUID.fromString(getString(R.string.latitude_longitude_uuid)));
        }

        @Override
        public void onDescriptorWrite(BluetoothGatt gatt, BluetoothGattDescriptor descriptor, int status) {
             super.onDescriptorWrite(gatt, descriptor, status);
             if(status == mBluetoothGatt.GATT_SUCCESS) {
                 Log.i(TAG, "wrote descriptor");
                 setConnText("Connected\nServices discovered\nWrote descriptors");
             }
        }

        @Override
        public void onCharacteristicChanged(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic) {
            super.onCharacteristicChanged(gatt, characteristic);
            byte[] charByte = characteristic.getValue();
            Log.i(TAG, "CabSense->Notifications notification changed to " + charByte.toString());

            if(charByte[0] == 0x01) {
                Log.i(TAG, "received CabSense->Notification value: " + charByte.toString());
                setMText("Warning: You are forgetting something alive\n(or at least warm) in your car!");
                vib.vibrate(1000);
            }
            else if(charByte[0] == 0x00)
            {
                Log.i(TAG, "warning notification recieved, but don't panic");
            }
            else
            {
                Log.i(TAG, "unknown status!");
            }

            //reset characteristic to 0 so that characteristicChanged can trigger again
            charByte[0] = 0x00;
            characteristic.setValue(charByte);
        }

       /* @Override
        public void onCharacteristicRead(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status) {
            super.onCharacteristicRead(gatt, characteristic, status);
            Log.i(TAG, "read CabSense->Notification characteristic");
        }*/

        @Override
        public void onCharacteristicWrite(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status) {
            super.onCharacteristicWrite(gatt, characteristic, status);
            if(status == mBluetoothGatt.GATT_SUCCESS) {
                charWrite = true;
                Log.i(TAG, "Longitude and Latitude characteristics written to");
                setConnText("Connected\nWrote longitude and latitude");
            }
        }
    };

    // callback for Bluetooth LE Scanner functions
    private ScanCallback mScanCallback = new ScanCallback() {
        @Override
        public void onScanResult(int callbackType, ScanResult result) {
            super.onScanResult(callbackType, result);
            Log.v("SCAN", "in scan callback");
            if( result == null || result.getDevice() == null)
            {   //unsuccessful scan for "cabsense"
                mText.setText("Failed to find " + getString(R.string.adv_device_name));
                return;
            }
            else
            {
                //successful scan for "cabsense"
                byte[] dev_bytes = result.getScanRecord().getBytes();
                String dev_name = new String(dev_bytes, StandardCharsets.UTF_8);
                StringBuilder builder = new StringBuilder( result.getDevice().getName() );
                builder.append("\n").append(result.getDevice().getAddress());
                mText.setText(builder.toString());

                mDevice = result.getDevice();
                mBluetoothGatt = mDevice.connectGatt(mContext, true, mBluetoothGattCallback, BluetoothDevice.TRANSPORT_LE);
                //mBluetoothLeScanner.stopScan(mScanCallback);
            }
        }

        @Override
        public void onBatchScanResults(List<ScanResult> results) {
            super.onBatchScanResults(results);
        }

        @Override
        public void onScanFailed(int errorCode) {
            Log.e( "BLE", "Discovery onScanFailed: " + errorCode );
            super.onScanFailed(errorCode);
        }
    };

    // discover process, looking for "cabsense" device
    private void discover() {
        List<ScanFilter> filters = new ArrayList<ScanFilter>();
        ScanFilter filter = new ScanFilter.Builder()
                .setDeviceName(getString(R.string.adv_device_name ))
                .build();
        filters.add( filter );

        ScanSettings settings = new ScanSettings.Builder()
                .setScanMode( ScanSettings.SCAN_MODE_LOW_POWER)
                .setCallbackType(ScanSettings.CALLBACK_TYPE_ALL_MATCHES)
                .build();

        mBluetoothLeScanner.startScan(filters, settings, mScanCallback);

        connText.setText("Scanning");

        mHandler.postDelayed(new Runnable() {
            @Override
            public void run() {
                mBluetoothLeScanner.stopScan(mScanCallback);
            }
        }, 10000);
    }

    // function called by "Write Location" button in the UI
    private void writeLocation(Double doubleLat, Double doubleLon){
        if (mBluetoothGatt != null && mBluetoothGattCharacteristicLoc != null) {

            if(doubleLat == null || doubleLon == null)
                Log.d(TAG, "lat and long doubles were null!");
            /*
            BLE server expects 32-bit int with resolution of 1/(10^7)
            32-bit signed int range: -2,147,483,648 to 2,147,483,647
            which is -214.7483648 to 214.7483647 with required resolution
            which fully covers the necessary -180 to 180 degree range

            Multiply values from loc.getLatitude() and loc.getLongitude() by 10^7 and convert to 32-bit signed int
            Will need to divide by (10^7) on server to get original values with required resolution
            */

            doubleLat *= 10000000;
            doubleLon *= 10000000;

            Float floLat, floLon;
            floLat = doubleLat.floatValue();
            floLon = doubleLon.floatValue();

            int intLat, intLon;
            intLat = floLat.intValue();
            intLon = floLon.intValue();

            byte[] byteLat = new byte[4];
            byte[] byteLon = new byte[4];

            // values are written little-endian

            byteLat[3] = (byte) (intLat >> 24);
            byteLat[2] = (byte) (intLat >> 16);
            byteLat[1] = (byte) (intLat >> 8);
            byteLat[0] = (byte) (intLat);
            byteLon[3] = (byte) (intLon >> 24);
            byteLon[2] = (byte) (intLon >> 16);
            byteLon[1] = (byte) (intLon >> 8);
            byteLon[0] = (byte) (intLon);

            byte[] locationBytes = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    byteLat[0], byteLat[1], byteLat[2], byteLat[3],
                    byteLon[0], byteLon[1], byteLon[2], byteLon[3]};
            boolean locationVal = mBluetoothGattCharacteristicLoc.setValue(locationBytes);

            if(locationVal == true)
                Log.i(TAG, "set location values");
            boolean status = mBluetoothGatt.writeCharacteristic(mBluetoothGattCharacteristicLoc);
            if(status == true) {
                Log.i(TAG, "wrote location characteristic");

                Log.d(TAG, "bytesLat: " + byteLat.toString());
                Log.d(TAG, "bytesLon: " + byteLon.toString());
            }
        }
    }

    @Override
    public void onClick(View v) {
        if( v.getId() == R.id.discover_btn ) {
            discover();
        }
        if(v.getId() == R.id.write_btn){
            writeLocation(doubleLat, doubleLon);
        }

    }

    //Method to Check if GPS is enabled or disabled
    private Boolean displayGpsStatus() {
        ContentResolver contentResolver = getBaseContext()
                .getContentResolver();
        boolean gpsStatus = Settings.Secure
                .isLocationProviderEnabled(contentResolver,
                        LocationManager.GPS_PROVIDER);
        if (gpsStatus) {
            return true;

        } else {
            return false;
        }
    }

    //Listener class to get coordinates
    private class MyLocationListener implements LocationListener {
        @Override
        public void onLocationChanged(Location loc) {

            editLocation.setText("");
            Toast.makeText(getBaseContext(),"Location changed : Lat: " +
                            loc.getLatitude()+ " Lng: " + loc.getLongitude(),
                    Toast.LENGTH_SHORT).show();
            String longitude = "Longitude: " +loc.getLongitude();
            Log.v(TAG, longitude);
            String latitude = "Latitude: " +loc.getLatitude();
            Log.v(TAG, latitude);

            doubleLon = loc.getLongitude();
            doubleLat = loc.getLatitude();

            String s = longitude+"\n"+latitude;
            editLocation.setText(s);
        }

        // not expecting provider to change from GPS to provider
        @Override
        public void onProviderDisabled(String provider) {
            // TODO Auto-generated method stub
        }

        // not expecting a different provider (than GPS) to become enabled
        @Override
        public void onProviderEnabled(String provider) {
            // TODO Auto-generated method stub
        }

        // not expecting provider (GPS) status to change
        @Override
        public void onStatusChanged(String provider,
                                    int status, Bundle extras) {
            // TODO Auto-generated method stub
        }
    }

}