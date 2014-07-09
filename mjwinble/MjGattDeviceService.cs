using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace matsujirushi.mjwinble
{
    public class MjGattDeviceService
    {
        /// <summary>
        /// BluetoothLEデバイスのInterfaceClassGuid
        /// </summary>
        private static Guid GUID_BLUETOOTHLE_DEVICE_INTERFACE = new Guid("781AEE18-7733-4CE4-ADD0-91F41C67B592");

        /// <summary>
        /// GATTサービスのInterfaceClassGuid
        /// </summary>
        private static Guid GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE = new Guid("6E3BB679-4372-40C8-9EAA-4509DF260CD8");

        /// <summary>
        /// BluetoothLEデバイスのAQS文字列を取得します。
        /// </summary>
        /// <returns></returns>
        public static string GetDeviceSelector()
        {
            return string.Concat("System.Devices.InterfaceClassGuid:=\"{", GUID_BLUETOOTHLE_DEVICE_INTERFACE.ToString(), "}\" AND System.Devices.InterfaceEnabled:=System.StructuredQueryType.Boolean#True");
        }

        /// <summary>
        /// BluetoothLEデバイスのAQS文字列を取得します。
        /// </summary>
        /// <param name="containerId">ContainerId</param>
        /// <returns></returns>
        public static string GetDeviceSelector(Guid containerId)
        {
            return string.Concat("System.Devices.InterfaceClassGuid:=\"{", GUID_BLUETOOTHLE_DEVICE_INTERFACE.ToString(), "}\" AND System.Devices.ContainerId:=\"{", containerId.ToString(), "}\" AND System.Devices.InterfaceEnabled:=System.StructuredQueryType.Boolean#True");
        }

        /// <summary>
        /// GATTサービスのAQS文字列を取得します。
        /// </summary>
        /// <returns></returns>
        public static string GetServiceSelector()
        {
            return string.Concat("System.Devices.InterfaceClassGuid:=\"{", GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE.ToString(), "}\" AND System.Devices.InterfaceEnabled:=System.StructuredQueryType.Boolean#True");
        }

        /// <summary>
        /// GATTサービスのAQS文字列を取得します。
        /// </summary>
        /// <param name="containerId"></param>
        /// <returns></returns>
        public static string GetServiceSelector(Guid containerId)
        {
            return string.Concat("System.Devices.InterfaceClassGuid:=\"{", GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE.ToString(), "}\" AND System.Devices.ContainerId:=\"{", containerId.ToString(), "}\" AND System.Devices.InterfaceEnabled:=System.StructuredQueryType.Boolean#True");
        }

    }
}
