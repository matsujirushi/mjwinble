using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Text.RegularExpressions;

using Windows.Devices.Enumeration;

namespace matsujirushi.mjwinble
{
    /// <summary>
    /// BluetoothLEデバイス/GATTサービスのクラスです。
    /// </summary>
    public static class MjGattDeviceService
    {
        /// <summary>
        /// BluetoothLEデバイスのInterfaceClassGuid
        /// </summary>
        private static Guid GUID_BLUETOOTHLE_DEVICE_INTERFACE = new Guid("781AEE18-7733-4CE4-ADD0-91F41C67B592");

        /// <summary>
        /// GATTサービスのInterfaceClassGuid
        /// </summary>
        private static Guid GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE = new Guid("6E3BB679-4372-40C8-9EAA-4509DF260CD8");

        public static string ServiceSpecificationNameFromServiceUuid(Guid uuid)
        {
            switch (uuid.ToString())
            {
                case "00001811-0000-1000-8000-00805f9b34fb":
                    return "Alert Notification Service";
                case "0000180f-0000-1000-8000-00805f9b34fb":
                    return "Battery Service";
                case "00001810-0000-1000-8000-00805f9b34fb":
                    return "Blood Pressure";
                case "00001805-0000-1000-8000-00805f9b34fb":
                    return "Current Time Service";
                case "00001818-0000-1000-8000-00805f9b34fb":
                    return "Cycling Power";
                case "00001816-0000-1000-8000-00805f9b34fb":
                    return "Cycling Speed and Cadence";
                case "0000180a-0000-1000-8000-00805f9b34fb":
                    return "Device Information";
                case "00001800-0000-1000-8000-00805f9b34fb":
                    return "Generic Access";
                case "00001801-0000-1000-8000-00805f9b34fb":
                    return "Generic Attribute";
                case "00001808-0000-1000-8000-00805f9b34fb":
                    return "Glucose";
                case "00001809-0000-1000-8000-00805f9b34fb":
                    return "Health Thermometer";
                case "0000180d-0000-1000-8000-00805f9b34fb":
                    return "Heart Rate";
                case "00001812-0000-1000-8000-00805f9b34fb":
                    return "Human Interface Device";
                case "00001802-0000-1000-8000-00805f9b34fb":
                    return "Immediate Alert";
                case "00001803-0000-1000-8000-00805f9b34fb":
                    return "Link Loss";
                case "00001819-0000-1000-8000-00805f9b34fb":
                    return "Location and Navigation";
                case "00001807-0000-1000-8000-00805f9b34fb":
                    return "Next DST Change Service";
                case "0000180e-0000-1000-8000-00805f9b34fb":
                    return "Phone Alert Status Service";
                case "00001806-0000-1000-8000-00805f9b34fb":
                    return "Reference Time Update Service";
                case "00001814-0000-1000-8000-00805f9b34fb":
                    return "Running Speed and Cadence";
                case "00001813-0000-1000-8000-00805f9b34fb":
                    return "Scan Parameters";
                case "00001804-0000-1000-8000-00805f9b34fb":
                    return "Tx Power";
                case "0000181c-0000-1000-8000-00805f9b34fb":
                    return "User Data";
                default:
                    return uuid.ToString();
            }
        }

        /// <summary>
        /// BluetoothLEデバイスのAQS文字列を取得します。
        /// </summary>
        /// <returns>AQS文字列</returns>
        internal static string GetDeviceSelector()
        {
            return string.Concat("System.Devices.InterfaceClassGuid:=\"{", GUID_BLUETOOTHLE_DEVICE_INTERFACE.ToString(), "}\" AND System.Devices.InterfaceEnabled:=System.StructuredQueryType.Boolean#True");
        }

        /// <summary>
        /// GATTサービスのAQS文字列を取得します。
        /// </summary>
        /// <returns>AQS文字列</returns>
        internal static string GetServiceSelector()
        {
            return string.Concat("System.Devices.InterfaceClassGuid:=\"{", GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE.ToString(), "}\" AND System.Devices.InterfaceEnabled:=System.StructuredQueryType.Boolean#True");
        }

        /// <summary>
        /// GATTサービスのAQS文字列を取得します。
        /// </summary>
        /// <param name="containerId">System.Devices.ContainerId</param>
        /// <returns>AQS文字列</returns>
        internal static string GetServiceSelector(Guid containerId)
        {
            return string.Concat("System.Devices.InterfaceClassGuid:=\"{", GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE.ToString(), "}\" AND System.Devices.ContainerId:=\"{", containerId.ToString(), "}\" AND System.Devices.InterfaceEnabled:=System.StructuredQueryType.Boolean#True");
        }

        /// <summary>
        /// GATTサービス情報からサービスUUIDを取得します。
        /// </summary>
        /// <param name="serviceInfo">GATTサービス情報</param>
        /// <returns>サービスUUID</returns>
        public static Guid UuidFromServiceInformation(DeviceInformation serviceInfo)
        {
            Regex regex = new Regex(@"^BTHLEDevice\\\{(.*)\}");
            var match = regex.Match((string)serviceInfo.Properties["System.Devices.DeviceInstanceId"]);
            if (!match.Success)
            {
                throw new ApplicationException();   // TODO
            }

            return new Guid(match.Groups[1].Value);
        }

    }
}
