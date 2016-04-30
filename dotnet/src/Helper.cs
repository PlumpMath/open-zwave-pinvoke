using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OpenZWaveDotNet
{
    class Helper
    {
        public static string[] MarshalUnmananagedStrArray2ManagedStrArray(IntPtr pUnmanagedStringArray, int stringCount)
        {
            if (stringCount == 0)
                return new string[0];

            IntPtr[] pIntPtrArray = new IntPtr[stringCount];
            string[] managedStringArray = new string[stringCount];

            Marshal.Copy(pUnmanagedStringArray, pIntPtrArray, 0, stringCount);

            for (int i = 0; i < stringCount; i++)
            {
                managedStringArray[i] = Marshal.PtrToStringAnsi(pIntPtrArray[i]);
                NativeWrapper.Free(pIntPtrArray[i]);
            }
            NativeWrapper.Free(pUnmanagedStringArray);
            return managedStringArray;
        }

        public static string ToString(IntPtr ptr)
        {
            try
            {
                return Marshal.PtrToStringAnsi(ptr);
            }
            finally
            {
                NativeWrapper.Free(ptr);
            }
        }
    }
}
