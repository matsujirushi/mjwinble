// mjwinbleproto.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"

#include <vector>

using namespace System;
using namespace System::Collections::Generic;

String^ BleUUIDtoString(const BTH_LE_UUID& uuid)
{
	if (uuid.IsShortUuid)
	{
		Text::StringBuilder^ sb = gcnew Text::StringBuilder();
		sb->AppendFormat("{0:X4}", uuid.Value.ShortUuid);
		switch (uuid.Value.ShortUuid)
		{
			// Generic Attribute Profile (GATT) 
			// https://www.bluetooth.org/en-us/specification/assigned-numbers/generic-attribute-profile
		case 0x1800:
			sb->Append("<<Generic Access Profile>>");
			break;
		case 0x1801:
			sb->Append("<<Generic Attribute Profile>>");
			break;
		case 0x2800:
			sb->Append("<<Primary Service>>");
			break;
		case 0x2801:
			sb->Append("<<Secondary Service>>");
			break;
		case 0x2802:
			sb->Append("<<Include>>");
			break;
		case 0x2803:
			sb->Append("<<Characteristic>>");
			break;
		case 0x2900:
			sb->Append("<<Characteristic Extended Properties>>");
			break;
		case 0x2901:
			sb->Append("<<Characteristic User Description>>");
			break;
		case 0x2902:
			sb->Append("<<Client Characteristic Configuration>>");
			break;
		case 0x2903:
			sb->Append("<<Server Characteristic Configuration>>");
			break;
		case 0x2904:
			sb->Append("<<Characteristic Format>>");
			break;
		case 0x2905:
			sb->Append("<<Characteristic Aggregate Format>>");
			break;
		case 0x2A00:
			sb->Append("<<Device Name>>");
			break;
		case 0x2A01:
			sb->Append("<<Appearance>>");
			break;
		case 0x2A02:
			sb->Append("<<Peripheral Privacy Flag>>");
			break;
		case 0x2A03:
			sb->Append("<<Reconnection Address>>");
			break;
		case 0x2A04:
			sb->Append("<<Peripheral Preferred Connection Parameters>>");
			break;
		case 0x2A05:
			sb->Append("<<Service Changed>>");
			break;
			// Services
			// https://developer.bluetooth.org/gatt/services/Pages/ServicesHome.aspx
		case 0x1811:
			sb->Append("<<Alert Notification Service>>");
			break;
		case 0x180F:
			sb->Append("<<Battery Service>>");
			break;
		case 0x1810:
			sb->Append("<<Blood Pressure>>");
			break;
		case 0x1805:
			sb->Append("<<Current Time Service>>");
			break;
		case 0x1818:
			sb->Append("<<Cycling Power>>");
			break;
		case 0x1816:
			sb->Append("<<Cycling Speed and Cadence>>");
			break;
		case 0x180A:
			sb->Append("<<Device Information>>");
			break;
			//case 0x1800:
			//	sb->Append("<<Generic Access>>");
			//	break;
			//case 0x1801:
			//	sb->Append("<<Generic Attribute>>");
			//	break;
		case 0x1808:
			sb->Append("<<Glucose>>");
			break;
		case 0x1809:
			sb->Append("<<Health Thermometer>>");
			break;
		case 0x180D:
			sb->Append("<<Heart Rate>>");
			break;
		case 0x1812:
			sb->Append("<<Human Interface Device>>");
			break;
		case 0x1802:
			sb->Append("<<Immediate Alert>>");
			break;
		case 0x1803:
			sb->Append("<<Link Loss>>");
			break;
		case 0x1819:
			sb->Append("<<Location and Navigation>>");
			break;
		case 0x1807:
			sb->Append("<<Next DST Change Service>>");
			break;
		case 0x180E:
			sb->Append("<<Phone Alert Status Service>>");
			break;
		case 0x1806:
			sb->Append("<<Reference Time Update Service>>");
			break;
		case 0x1814:
			sb->Append("<<Running Speed and Cadence>>");
			break;
		case 0x1813:
			sb->Append("<<Scan Parameters>>");
			break;
		case 0x1804:
			sb->Append("<<Tx Power>>");
			break;
		case 0x181C:
			sb->Append("<<User Data>>");
			break;
			// Characteristics
			//https://developer.bluetooth.org/gatt/characteristics/Pages/CharacteristicsHome.aspx
		case 0x2A7E:
			sb->Append("<<Aerobic Heart Rate Lower Limit>>");
			break;
		case 0x2A84:
			sb->Append("<<Aerobic Heart Rate Upper Limit>>");
			break;
		case 0x2A7F:
			sb->Append("<<Aerobic Threshold>>");
			break;
		case 0x2A80:
			sb->Append("<<Age>>");
			break;
		case 0x2A43:
			sb->Append("<<Alert Category ID>>");
			break;
		case 0x2A42:
			sb->Append("<<Alert Category ID Bit Mask>>");
			break;
		case 0x2A06:
			sb->Append("<<Alert Level>>");
			break;
		case 0x2A44:
			sb->Append("<<Alert Notification Control Point>>");
			break;
		case 0x2A3F:
			sb->Append("<<Alert Status>>");
			break;
		case 0x2A81:
			sb->Append("<<Anaerobic Heart Rate Lower Limit>>");
			break;
		case 0x2A82:
			sb->Append("<<Anaerobic Heart Rate Upper Limit>>");
			break;
		case 0x2A83:
			sb->Append("<<Anaerobic Threshold>>");
			break;
			//case 0x2A01:
			//	sb->Append("<<Appearance>>");
			//	break;
		case 0x2A19:
			sb->Append("<<Battery Level>>");
			break;
		case 0x2A49:
			sb->Append("<<Blood Pressure Feature>>");
			break;
		case 0x2A35:
			sb->Append("<<Blood Pressure Measurement>>");
			break;
		case 0x2A38:
			sb->Append("<<Body Sensor Location>>");
			break;
		case 0x2A22:
			sb->Append("<<Boot Keyboard Input Report>>");
			break;
		case 0x2A32:
			sb->Append("<<Boot Keyboard Output Report>>");
			break;
		case 0x2A33:
			sb->Append("<<Boot Mouse Input Report>>");
			break;
		case 0x2A5C:
			sb->Append("<<CSC Feature>>");
			break;
		case 0x2A5B:
			sb->Append("<<CSC Measurement>>");
			break;
		case 0x2A2B:
			sb->Append("<<Current Time>>");
			break;
		case 0x2A66:
			sb->Append("<<Cycling Power Control Point>>");
			break;
		case 0x2A65:
			sb->Append("<<Cycling Power Feature>>");
			break;
		case 0x2A63:
			sb->Append("<<Cycling Power Measurement>>");
			break;
		case 0x2A64:
			sb->Append("<<Cycling Power Vector>>");
			break;
		case 0x2A99:
			sb->Append("<<Database Change Increment>>");
			break;
		case 0x2A85:
			sb->Append("<<Date of Birth>>");
			break;
		case 0x2A86:
			sb->Append("<<Date of Threshold Assessment >>");
			break;
		case 0x2A08:
			sb->Append("<<Date Time>>");
			break;
		case 0x2A0A:
			sb->Append("<<Day Date Time>>");
			break;
		case 0x2A09:
			sb->Append("<<Day of Week>>");
			break;
			//case 0x2A00:
			//	sb->Append("<<Device Name>>");
			//	break;
		case 0x2A0D:
			sb->Append("<<DST Offset>>");
			break;
		case 0x2A87:
			sb->Append("<<Email Address>>");
			break;
		case 0x2A0C:
			sb->Append("<<Exact Time 256>>");
			break;
		case 0x2A88:
			sb->Append("<<Fat Burn Heart Rate Lower Limit>>");
			break;
		case 0x2A89:
			sb->Append("<<Fat Burn Heart Rate Upper Limit>>");
			break;
		case 0x2A26:
			sb->Append("<<Firmware Revision String>>");
			break;
		case 0x2A8A:
			sb->Append("<<First Name>>");
			break;
		case 0x2A8B:
			sb->Append("<<Five Zone Heart Rate Limits>>");
			break;
		case 0x2A8C:
			sb->Append("<<Gender>>");
			break;
		case 0x2A51:
			sb->Append("<<Glucose Feature>>");
			break;
		case 0x2A18:
			sb->Append("<<Glucose Measurement>>");
			break;
		case 0x2A34:
			sb->Append("<<Glucose Measurement Context>>");
			break;
		case 0x2A27:
			sb->Append("<<Hardware Revision String>>");
			break;
		case 0x2A39:
			sb->Append("<<Heart Rate Control Point>>");
			break;
		case 0x2A8D:
			sb->Append("<<Heart Rate Max>>");
			break;
		case 0x2A37:
			sb->Append("<<Heart Rate Measurement>>");
			break;
		case 0x2A8E:
			sb->Append("<<Height>>");
			break;
		case 0x2A4C:
			sb->Append("<<HID Control Point>>");
			break;
		case 0x2A4A:
			sb->Append("<<HID Information>>");
			break;
		case 0x2A8F:
			sb->Append("<<Hip Circumference>>");
			break;
		case 0x2A2A:
			sb->Append("<<IEEE 11073-20601 Regulatory Certification Data List>>");
			break;
		case 0x2A36:
			sb->Append("<<Intermediate Cuff Pressure>>");
			break;
		case 0x2A1E:
			sb->Append("<<Intermediate Temperature>>");
			break;
		case 0x2AA2:
			sb->Append("<<Language>>");
			break;
		case 0x2A90:
			sb->Append("<<Last Name>>");
			break;
		case 0x2A6B:
			sb->Append("<<LN Control Point>>");
			break;
		case 0x2A6A:
			sb->Append("<<LN Feature>>");
			break;
		case 0x2A0F:
			sb->Append("<<Local Time Information>>");
			break;
		case 0x2A67:
			sb->Append("<<Location and Speed>>");
			break;
		case 0x2A29:
			sb->Append("<<Manufacturer Name String>>");
			break;
		case 0x2A91:
			sb->Append("<<Maximum Recommended Heart Rate>>");
			break;
		case 0x2A21:
			sb->Append("<<Measurement Interval>>");
			break;
		case 0x2A24:
			sb->Append("<<Model Number String>>");
			break;
		case 0x2A68:
			sb->Append("<<Navigation>>");
			break;
		case 0x2A46:
			sb->Append("<<New Alert>>");
			break;
			//case 0x2A04:
			//	sb->Append("<<Peripheral Preferred Connection Parameters>>");
			//	break;
			//case 0x2A02:
			//	sb->Append("<<Peripheral Privacy Flag>>");
			//	break;
		case 0x2A50:
			sb->Append("<<PnP ID>>");
			break;
		case 0x2A69:
			sb->Append("<<Position Quality>>");
			break;
		case 0x2A4E:
			sb->Append("<<Protocol Mode>>");
			break;
			//case 0x2A03:
			//	sb->Append("<<Reconnection Address>>");
			//	break;
		case 0x2A52:
			sb->Append("<<Record Access Control Point>>");
			break;
		case 0x2A14:
			sb->Append("<<Reference Time Information>>");
			break;
		case 0x2A4D:
			sb->Append("<<Report>>");
			break;
		case 0x2A4B:
			sb->Append("<<Report Map>>");
			break;
		case 0x2A92:
			sb->Append("<<Resting Heart Rate>>");
			break;
		case 0x2A40:
			sb->Append("<<Ringer Control Point>>");
			break;
		case 0x2A41:
			sb->Append("<<Ringer Setting>>");
			break;
		case 0x2A54:
			sb->Append("<<RSC Feature>>");
			break;
		case 0x2A53:
			sb->Append("<<RSC Measurement>>");
			break;
		case 0x2A55:
			sb->Append("<<SC Control Point>>");
			break;
		case 0x2A4F:
			sb->Append("<<Scan Interval Window>>");
			break;
		case 0x2A31:
			sb->Append("<<Scan Refresh>>");
			break;
		case 0x2A5D:
			sb->Append("<<Sensor Location>>");
			break;
		case 0x2A25:
			sb->Append("<<Serial Number String>>");
			break;
			//case 0x2A05:
			//	sb->Append("<<Service Changed>>");
			//	break;
		case 0x2A28:
			sb->Append("<<Software Revision String>>");
			break;
		case 0x2A93:
			sb->Append("<<Sport Type for Aerobic and Anaerobic Thresholds>>");
			break;
		case 0x2A47:
			sb->Append("<<Supported New Alert Category>>");
			break;
		case 0x2A48:
			sb->Append("<<Supported Unread Alert Category>>");
			break;
		case 0x2A23:
			sb->Append("<<System ID>>");
			break;
		case 0x2A1C:
			sb->Append("<<Temperature Measurement>>");
			break;
		case 0x2A1D:
			sb->Append("<<Temperature Type>>");
			break;
		case 0x2A94:
			sb->Append("<<Three Zone Heart Rate Limits>>");
			break;
		case 0x2A12:
			sb->Append("<<Time Accuracy>>");
			break;
		case 0x2A13:
			sb->Append("<<Time Source>>");
			break;
		}
		return sb->ToString();
	}
	else
	{
		Text::StringBuilder^ sb = gcnew Text::StringBuilder();
		sb->AppendFormat("{0:X8}", uuid.Value.LongUuid.Data1);
		sb->Append("-");
		sb->AppendFormat("{0:X4}", uuid.Value.LongUuid.Data2);
		sb->Append("-");
		sb->AppendFormat("{0:X4}", uuid.Value.LongUuid.Data3);
		sb->Append("-");
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[0]);
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[1]);
		sb->Append("-");
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[2]);
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[3]);
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[4]);
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[5]);
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[6]);
		sb->AppendFormat("{0:X2}", uuid.Value.LongUuid.Data4[7]);
		return sb->ToString();
	}
}

List<String^>^ BleGetDevicesPath(GUID interfaceGuid)
{

	List<String^>^ devicesPath = gcnew List<String^>();

	HDEVINFO radioHandle = SetupDiGetClassDevs(&interfaceGuid, NULL, NULL, DIGCF_DEVICEINTERFACE | DIGCF_PRESENT);
	if (radioHandle == INVALID_HANDLE_VALUE) throw gcnew ApplicationException();

	SP_DEVICE_INTERFACE_DATA device;
	ZeroMemory(&device, sizeof(device));
	device.cbSize = sizeof(device);
	for (DWORD i = 0; SetupDiEnumDeviceInterfaces(radioHandle, NULL, &interfaceGuid, i, &device); i++)
	{
		DWORD size = 0;
		if (SetupDiGetDeviceInterfaceDetail(radioHandle, &device, NULL, 0, &size, 0)) throw gcnew ApplicationException();
		if (GetLastError() != ERROR_INSUFFICIENT_BUFFER) throw gcnew ApplicationException();

		PSP_DEVICE_INTERFACE_DETAIL_DATA deviceDetail = (PSP_DEVICE_INTERFACE_DETAIL_DATA)new byte[size];
		ZeroMemory(deviceDetail, size);
		deviceDetail->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
		SP_DEVINFO_DATA deviceInfo;
		ZeroMemory(&deviceInfo, sizeof(deviceInfo));
		deviceInfo.cbSize = sizeof(deviceInfo);

		if (!SetupDiGetDeviceInterfaceDetail(radioHandle, &device, deviceDetail, size, &size, &deviceInfo)) throw gcnew ApplicationException();

		devicesPath->Add(gcnew String(deviceDetail->DevicePath));

		delete deviceDetail;
	}

	SetupDiDestroyDeviceInfoList(radioHandle);

	return devicesPath;
}

HANDLE BleOpenDevice(String^ devicePath)
{
	array<Char>^ array = devicePath->ToCharArray();
	pin_ptr<Char> pin = &array[0];

	HANDLE handle = CreateFile(pin, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (handle == INVALID_HANDLE_VALUE) throw gcnew ApplicationException();

	return handle;
}

void BleCloseDevice(HANDLE handle)
{
	CloseHandle(handle);
}

std::vector<BTH_LE_GATT_SERVICE*> BleGetGattServices(HANDLE device)
{
	USHORT num;
	HRESULT result = BluetoothGATTGetServices(device, 0, NULL, &num, BLUETOOTH_GATT_FLAG_NONE);
	if (result != HRESULT_FROM_WIN32(ERROR_MORE_DATA)) throw gcnew ApplicationException();

	PBTH_LE_GATT_SERVICE gattServices = (PBTH_LE_GATT_SERVICE)new byte[sizeof(BTH_LE_GATT_SERVICE) * num];
	ZeroMemory(gattServices, sizeof(BTH_LE_GATT_SERVICE) * num);
	result = BluetoothGATTGetServices(device, num, gattServices, &num, BLUETOOTH_GATT_FLAG_NONE);
	if (result != HRESULT_FROM_WIN32(S_OK)) throw gcnew ApplicationException();

	std::vector<BTH_LE_GATT_SERVICE*> services;
	for (int i = 0; i < num; i++)
	{
		services.push_back(&gattServices[i]);
	}

	//delete gattServices;

	return services;
}

std::vector<BTH_LE_GATT_CHARACTERISTIC*> BleGetGattCharacteristic(HANDLE device, const BTH_LE_GATT_SERVICE& service)
{
	USHORT num;
	HRESULT result = BluetoothGATTGetCharacteristics(device, (PBTH_LE_GATT_SERVICE)&service, 0, NULL, &num, BLUETOOTH_GATT_FLAG_NONE);
	if (result == HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) return std::vector<BTH_LE_GATT_CHARACTERISTIC*>();
	if (result != HRESULT_FROM_WIN32(ERROR_MORE_DATA)) throw gcnew ApplicationException();

	PBTH_LE_GATT_CHARACTERISTIC gattCharacteristics = (PBTH_LE_GATT_CHARACTERISTIC)new byte[sizeof(BTH_LE_GATT_CHARACTERISTIC) * num];
	ZeroMemory(gattCharacteristics, sizeof(BTH_LE_GATT_CHARACTERISTIC) * num);
	result = BluetoothGATTGetCharacteristics(device, (PBTH_LE_GATT_SERVICE)&service, num, gattCharacteristics, &num, BLUETOOTH_GATT_FLAG_NONE);
	if (result != HRESULT_FROM_WIN32(S_OK)) throw gcnew ApplicationException();

	std::vector<BTH_LE_GATT_CHARACTERISTIC*> characteristics;
	for (int i = 0; i < num; i++)
	{
		characteristics.push_back(&gattCharacteristics[i]);
	}

	//delete gattCharacteristics;

	return characteristics;
}

int main(array<System::String ^> ^args)
{
	GUID guid;

	// Bluetooth LE devices.
	//guid = GUID_BLUETOOTHLE_DEVICE_INTERFACE;

	// Specific service.
	guid = BTH_LE_ATT_BLUETOOTH_BASE_GUID;
	//guid.Data1 = 0x1809;	// <<Health Thermometer>>
	guid.Data1 = 0x180F;	// <<Battery Service>>

	List<String^>^ devicesPath = BleGetDevicesPath(guid);
	for (int deviceNum = 0; deviceNum < devicesPath->Count; deviceNum++)
	{
		Console::WriteLine("{0:d02}.       {1}", deviceNum, devicesPath[deviceNum]);

		HANDLE deviceHandle = BleOpenDevice(devicesPath[deviceNum]);

		std::vector<BTH_LE_GATT_SERVICE*> services = BleGetGattServices(deviceHandle);
		for (size_t serviceNum = 0; serviceNum < services.size(); serviceNum++)
		{
			std::vector<BTH_LE_GATT_CHARACTERISTIC*> characteristics = BleGetGattCharacteristic(deviceHandle, *services[serviceNum]);

			Console::WriteLine("{0:d02}.{1:d02}.    {2}", deviceNum, serviceNum, BleUUIDtoString(services[serviceNum]->ServiceUuid));
			for (size_t characteristicNum = 0; characteristicNum < characteristics.size(); characteristicNum++)
			{
				Console::WriteLine("{0:d02}.{1:d02}.{2:d02}. {3}", deviceNum, serviceNum, characteristicNum, BleUUIDtoString(characteristics[characteristicNum]->CharacteristicUuid));

				if (characteristics[characteristicNum]->IsReadable)
				{
					for (int i = 0; i < 5; i++)
					{
						USHORT valueSize;
						HRESULT hr = BluetoothGATTGetCharacteristicValue(deviceHandle, characteristics[characteristicNum], 0, NULL, &valueSize, BLUETOOTH_GATT_FLAG_NONE);
						if (hr != HRESULT_FROM_WIN32(ERROR_MORE_DATA)) throw gcnew ApplicationException();
						PBTH_LE_GATT_CHARACTERISTIC_VALUE value = (PBTH_LE_GATT_CHARACTERISTIC_VALUE)new byte[valueSize];
						ZeroMemory(value, valueSize);
						hr = BluetoothGATTGetCharacteristicValue(deviceHandle, characteristics[characteristicNum], valueSize, value, &valueSize, BLUETOOTH_GATT_FLAG_NONE);
						if (hr != HRESULT_FROM_WIN32(S_OK)) throw gcnew ApplicationException();
						Console::WriteLine("          -> {0}", value->Data[0]);
						System::Threading::Thread::Sleep(1000);
					}
				}
				else
				{
					Console::WriteLine();
				}
			}
		}

		BleCloseDevice(deviceHandle);
	}


	Console::ReadLine();
	return 0;
}
