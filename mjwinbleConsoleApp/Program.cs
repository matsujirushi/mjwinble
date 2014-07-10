﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Text.RegularExpressions;

// Windows Desktop Appから、WinRTを参照するには？
//
// 1. プロジェクトファイルのPropertyGroupエレメントに、"<TargetPlatformVersion>8.1</TargetPlatformVersion>"を追加します。
// 2. プロジェクトの参照設定で、コアのWindowsをチェックします。
// 3. プロジェクトの参照設定で、System.Runtimeを追加します。

using Windows.Foundation;
using Windows.Devices.Enumeration;
using Windows.Devices.Bluetooth.GenericAttributeProfile;
using Windows.Devices.Bluetooth;

using matsujirushi.mjwinble;

namespace mjwinbleConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("1. Device List -> Service List");
            Console.WriteLine("2. Service List");
            Console.WriteLine("3. Battery Service Only");
            Console.Write("Input: ");
            var workflow = int.Parse(Console.ReadLine());
            Console.WriteLine();

            DeviceInformationCollection servicesInfo;
            switch (workflow)
            {
                case 1:
                    {
                        // BluetoothLEデバイス一覧を表示します。
                        #region MjDeviceInformation.FindGattDevicesAsync()
                        var devicesInfoResult = MjDeviceInformation.FindGattDevicesAsync();
                        while (devicesInfoResult.Status == AsyncStatus.Started)
                        {
                            System.Threading.Thread.Sleep(100);
                        }
                        var devicesInfo = devicesInfoResult.GetResults();
                        for (int i = 0; i < devicesInfo.Count; i++)
                        {
                            Console.WriteLine("{0}. [{1}]", i + 1, devicesInfo[i].Name);
                        }
                        Console.Write("Input: ");
                        var deviceInfo = devicesInfo[int.Parse(Console.ReadLine()) - 1];
                        Console.WriteLine();
                        #endregion

                        // GATTサービス一覧を取得します。
                        #region MjDeviceInformation.FindGattServicesAsync(deviceInfo)
                        var servicesInfoResult = MjDeviceInformation.FindGattServicesAsync(deviceInfo);
                        while (servicesInfoResult.Status == AsyncStatus.Started)
                        {
                            System.Threading.Thread.Sleep(100);
                        }
                        servicesInfo = servicesInfoResult.GetResults();
                        #endregion
                    }
                    break;

                case 2:
                    {
                        // GATTサービス一覧を取得します。
                        #region MjDeviceInformation.FindGattServicesAsync()
                        var servicesInfoResult = MjDeviceInformation.FindGattServicesAsync();
                        while (servicesInfoResult.Status == AsyncStatus.Started)
                        {
                            System.Threading.Thread.Sleep(100);
                        }
                        servicesInfo = servicesInfoResult.GetResults();
                        #endregion
                    }
                    break;

                case 3:
                    {
                        // GATTサービス一覧を取得します。
                        #region MjDeviceInformation.FindGattServicesAsync(0x180f)
                        var servicesInfoResult = MjDeviceInformation.FindGattServicesAsync(0x180f);
                        while (servicesInfoResult.Status == AsyncStatus.Started)
                        {
                            System.Threading.Thread.Sleep(100);
                        }
                        servicesInfo = servicesInfoResult.GetResults();
                        #endregion
                    }
                    break;

                default:
                    return;
            }

            // GATTサービスを選択します。
            for (int i = 0; i < servicesInfo.Count; i++)
            {
                var uuid = MjGattDeviceService.UuidFromServiceInformation(servicesInfo[i]);
                var uuidString = MjGattDeviceService.ServiceSpecificationNameFromServiceUuid(uuid);
                Console.WriteLine("{0}. [{1}.{2}]", i + 1, servicesInfo[i].Name, uuidString);
            }
            Console.Write("Input: ");
            var serviceInfo = servicesInfo[int.Parse(Console.ReadLine()) - 1];
            Console.WriteLine();

            // GATTサービスインスタンスを取得します。
            var service = GattDeviceServiceFromId(serviceInfo.Id);

            // Characteristicを取得します。
            var characteristics = service.GetCharacteristics(GattDeviceService.ConvertShortIdToUuid(0x2A19));   // Battery Level

            // Battery Level値を取得します。
            for (int i = 0; i < 10; i++)
            {
                var val = GattCharacteristicReadValue(characteristics[0]);

                Console.WriteLine("Battery Level = {0}", Windows.Storage.Streams.DataReader.FromBuffer(val.Value).ReadByte());
            }

            Console.Write("Completed: ");
            Console.ReadKey();
        }

        private static GattDeviceService GattDeviceServiceFromId(string id)
        {
            var result = GattDeviceService.FromIdAsync(id);
            while (result.Status == AsyncStatus.Started)
            {
                System.Threading.Thread.Sleep(100);
            }

            return result.GetResults();
        }

        private static GattReadResult GattCharacteristicReadValue(GattCharacteristic characteristic)
        {
            var result = characteristic.ReadValueAsync(BluetoothCacheMode.Uncached);
            while (result.Status == AsyncStatus.Started)
            {
                System.Threading.Thread.Sleep(100);
            }

            return result.GetResults();
        }

    }
}
