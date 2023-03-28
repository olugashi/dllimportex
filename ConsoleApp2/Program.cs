using System.Runtime.InteropServices;
using static System.Net.Mime.MediaTypeNames;

namespace ConsoleApp2
{
    internal class Program
    {
        [DllImport("NativeCppDll.dll")]
        static extern void Test();

        [DllImport("NativeCppDll.dll")]
        static extern void TestPoint(Point p);

        [DllImport("NativeCppDll.dll")]
        static extern void TestArray(ref int[] arr);

        [DllImport("NativeCppDll.dll")]
        static extern IntPtr TestReturnArrayPtr(IntPtr ptr);


        static void Main(string[] args)
        {
            Test();

            TestPoint(new Point() { X = 5, Y = 8 });

            /*TestStruct data = new TestStruct();
            data.values = new int[10];

            for (int i = 0; i < 10; i++)
            {
                data.values[i] = i;
            }
            TestArray(ref data.values);*/

            int size = Marshal.SizeOf(typeof(TestStruct));


            IntPtr pnt = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(TestStruct)));
            var data = new TestStructPtr();

            data.values = new int[10];

            /*for (int i = 0; i < 10; i++)
            {
                data1.values[i] = i;
            }*/
            Marshal.StructureToPtr(data, pnt, false);

            var ptr =TestReturnArrayPtr(pnt);

            var ver = Marshal.PtrToStructure(ptr, typeof(TestStructPtr));

            Console.WriteLine("Hello, World!");
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Point
    {
        public int X;
        public int Y;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct TestStruct
    { // note typedef is not needed */
        public int length;

        [MarshalAs (UnmanagedType.ByValArray , SizeConst = 10)]
        public int[] values; // specified the size

    }
    
    [StructLayout(LayoutKind.Sequential)]
    public struct TestStructPtr
    { // note typedef is not needed */
        public int length;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 10)]
        public int[] values; // specified the size
       
    };
}