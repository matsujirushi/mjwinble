using System;
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
using System.Runtime.InteropServices.WindowsRuntime;

using matsujirushi.mjwinble;

namespace mjwinbleConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            // BluetoothLEデバイス一覧を表示します。
            var devicesInfo = DeviceInformationFindAll(MjGattDeviceService.GetDeviceSelector());
            for (int i = 0; i < devicesInfo.Count; i++)
            {
                Console.WriteLine("{0}. [{1}]", i + 1, devicesInfo[i].Name);
            }
            Console.Write("Input: ");
            var deviceInfo = devicesInfo[int.Parse(Console.ReadLine()) - 1];
            Console.WriteLine();

            // GATTサービス一覧を表示します。
            var servicesInfo = DeviceInformationFindAll(MjGattDeviceService.GetServiceSelector((Guid)deviceInfo.Properties["System.Devices.ContainerId"]));
            for (int i = 0; i < servicesInfo.Count; i++)
            {
                var uuid = UuidFromDeviceInstanceId((string)servicesInfo[i].Properties["System.Devices.DeviceInstanceId"]);
                Console.WriteLine("{0}. [{1}]", i + 1, uuid);
            }
            Console.Write("Input: ");
            var serviceInfo = servicesInfo[int.Parse(Console.ReadLine()) - 1];
            Console.WriteLine();

            // GATTサービスインスタンスを取得します。
            var result = GattDeviceService.FromIdAsync(serviceInfo.Id);
            while (result.Status == AsyncStatus.Started)
            {
                System.Threading.Thread.Sleep(100);
            }
            var service = result.GetResults();

            // Characteristicを取得します。
            var characteristics = service.GetCharacteristics(GattDeviceService.ConvertShortIdToUuid(0x2A19));   // Battery Level

            // Battery Level値を取得します。
            for (int i = 0; i < 10; i++)
            {
                var result2 = characteristics[0].ReadValueAsync(Windows.Devices.Bluetooth.BluetoothCacheMode.Uncached);
                while (result2.Status == AsyncStatus.Started)
                {
                    System.Threading.Thread.Sleep(100);
                }
                var crValue = result2.GetResults();

                Console.WriteLine("Battery Level = {0}", Windows.Storage.Streams.DataReader.FromBuffer(crValue.Value).ReadByte());
            }

            Console.Write("Completed: ");
            Console.ReadKey();
        }

        private static DeviceInformationCollection DeviceInformationFindAll(string aqsFilter)
        {
            var result = DeviceInformation.FindAllAsync(aqsFilter, new string[] { "System.Devices.ContainerId", "System.Devices.InterfaceClassGuid" });
            while (result.Status == AsyncStatus.Started)
            {
                System.Threading.Thread.Sleep(100);
            }

            return result.GetResults();
        }

        private static Guid UuidFromDeviceInstanceId(string deviceInstanceId)
        {
            Regex regex = new Regex(@"^BTHLEDevice\\\{(.*)\}");
            var match = regex.Match(deviceInstanceId);
            if (!match.Success)
            {
                throw new ApplicationException();
            }

            return new Guid(match.Groups[1].Value);
        }

    }
}
