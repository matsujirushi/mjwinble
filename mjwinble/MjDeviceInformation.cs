using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Windows.Foundation;
using Windows.Devices.Enumeration;
using Windows.Devices.Bluetooth.GenericAttributeProfile;

namespace matsujirushi.mjwinble
{
    /// <summary>
    /// デバイス情報のクラスです。
    /// </summary>
    public static class MjDeviceInformation
    {
        /// <summary>
        /// BluetoothLEデバイス情報を取得します。
        /// </summary>
        /// <returns>BluetoothLEデバイス</returns>
        public static IAsyncOperation<DeviceInformationCollection> FindGattDevicesAsync()
        {
            return DeviceInformation.FindAllAsync(MjGattDeviceService.GetDeviceSelector(), new string[] { "System.Devices.ContainerId", "System.Devices.InterfaceClassGuid" });
        }

        /// <summary>
        /// GATTサービス情報を取得します。
        /// </summary>
        /// <returns>GATTサービス情報</returns>
        public static IAsyncOperation<DeviceInformationCollection> FindGattServicesAsync()
        {
            return DeviceInformation.FindAllAsync(MjGattDeviceService.GetServiceSelector(), new string[] { "System.Devices.ContainerId", "System.Devices.InterfaceClassGuid" });
        }

        /// <summary>
        /// GATTサービス情報を取得します。
        /// </summary>
        /// <param name="deviceInfo">BluetoothLEデバイス情報</param>
        /// <returns>GATTサービス情報</returns>
        public static IAsyncOperation<DeviceInformationCollection> FindGattServicesAsync(DeviceInformation deviceInfo)
        {
            return DeviceInformation.FindAllAsync(MjGattDeviceService.GetServiceSelector((Guid)deviceInfo.Properties["System.Devices.ContainerId"]), new string[] { "System.Devices.ContainerId", "System.Devices.InterfaceClassGuid" });
        }

        /// <summary>
        /// GATTサービス情報を取得します。
        /// </summary>
        /// <param name="serviceShortId">サービスID</param>
        /// <returns>GATTサービス情報</returns>
        public static IAsyncOperation<DeviceInformationCollection> FindGattServicesAsync(ushort serviceShortId)
        {
            return DeviceInformation.FindAllAsync(GattDeviceService.GetDeviceSelectorFromShortId(serviceShortId), new string[] { "System.Devices.ContainerId", "System.Devices.InterfaceClassGuid" });
        }

        /// <summary>
        /// GATTサービス情報を取得します。
        /// </summary>
        /// <param name="serviceUuid">サービスUUID</param>
        /// <returns>GATTサービス情報</returns>
        public static IAsyncOperation<DeviceInformationCollection> FindGattServicesAsync(Guid serviceUuid)
        {
            return DeviceInformation.FindAllAsync(GattDeviceService.GetDeviceSelectorFromUuid(serviceUuid), new string[] { "System.Devices.ContainerId", "System.Devices.InterfaceClassGuid" });
        }

    }
}
