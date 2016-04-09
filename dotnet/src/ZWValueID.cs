using System;
using System.Runtime.InteropServices;

namespace OpenZWaveDotNet
{
    public class ZWValueID
    {
        public enum ValueGenre
        {
            Basic = 0,
            User = 1,
            Config = 2,
            System = 3,
            Count = 4
        };

        public enum ValueType
        {
            Bool = 0,
            Byte = 1,
            Decimal = 2,
            Int = 3,
            List = 4,
            Schedule = 5,
            Short = 6,
            String = 7,
            Button = 8,
            Raw = 9,
            Max = 10
        };

        ~ZWValueID()
        {
            Delete();
        }

        private ulong Id { get; set; }
        private ValueGenre Genre { get; set; }
        private byte CommandClassId { get; set; }
        private ValueType Type { get; set; }
        private int Index { get; set; }
        internal IntPtr IntPtr { get; private set; }


        internal ZWValueID(IntPtr valueID)
        {
            IntPtr = valueID;
            Id = NativeWrapper.GetValueId(valueID);

            CommandClassId = NativeWrapper.GetValueCommandClassId(valueID);
            Type = (ValueType)NativeWrapper.GetValueType(valueID);
            Index = (int)NativeWrapper.GetValueIndex(valueID);
            Genre = (ValueGenre)NativeWrapper.GetValueGenre(valueID);
        }

        public ulong GetId()
        {
            return Id;
        }

        public ValueGenre GetGenre()
        {
            return Genre;
        }

        public byte GetCommandClassId()
        {
            return CommandClassId;
        }
        public new ValueType GetType()
        {
            return Type;
        }

        public int GetIndex()
        {
            return Index;
        }

        internal void Delete()
        {
            if (IntPtr != IntPtr.Zero)
                NativeWrapper.DeleteValue(IntPtr);
            IntPtr = IntPtr.Zero;
        }
    }
}