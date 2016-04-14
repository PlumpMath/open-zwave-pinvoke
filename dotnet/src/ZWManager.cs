using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace OpenZWaveDotNet
{
    public delegate void ManagedNotificationsHandler(ZWNotification notification);

    public class ZWManager
    {
        public ManagedNotificationsHandler OnNotification { get; set; }

        public void Create()
        {
            NativeWrapper.CreateManager();
            NativeWrapper.AddWatcher((n, c) =>
            {
                if (OnNotification != null)
                    OnNotification(new ZWNotification(n));

            }, IntPtr.Zero);
        }

        public void AddDriver(string controllerPath)
        {
            NativeWrapper.AddDriver(controllerPath);
        }

        public void WriteConfig(uint homeId)
        {
            NativeWrapper.WriteConfig(homeId);
        }

        public void GetValueAsBool(ZWValueID valueId, out bool ovalue)
        {
            NativeWrapper.GetValueAsBool(valueId.IntPtr, out ovalue);
        }

        public void GetValueAsByte(ZWValueID valueId, out byte ovalue)
        {
            NativeWrapper.GetValueAsByte(valueId.IntPtr, out ovalue);
        }

        public void GetValueAsFloat(ZWValueID valueId, out float ovalue)
        {
            NativeWrapper.GetValueAsFloat(valueId.IntPtr, out ovalue);
        }

        public void GetValueAsInt(ZWValueID valueId, out int ovalue)
        {
            NativeWrapper.GetValueAsInt(valueId.IntPtr, out ovalue);
        }

        public void GetValueListItems(ZWValueID valueId, out string[] ovalue)
        {
            int count = 0;
            IntPtr items = IntPtr.Zero;
            if (NativeWrapper.GetValueListItems(valueId.IntPtr, out items, ref count))
                ovalue = Helper.MarshalUnmananagedStrArray2ManagedStrArray(items, count);
            else
                ovalue = new string[0];
        }

        public void GetValueAsShort(ZWValueID valueId, out short ovalue)
        {
            NativeWrapper.GetValueAsShort(valueId.IntPtr, out ovalue);
        }

        public void GetValueAsString(ZWValueID valueId, out string ovalue)
        {
            IntPtr ptr;
            NativeWrapper.GetValueAsString(valueId.IntPtr, out ptr);
            ovalue = Helper.ToString(ptr);
        }

        public void SetValue(ZWValueID valueId, bool value)
        {
            NativeWrapper.SetValueFromBool(valueId.IntPtr, value);
        }

        public void SetValue(ZWValueID valueId, float value)
        {
            NativeWrapper.SetValueFromFloat(valueId.IntPtr, value);
        }

        public void SetValue(ZWValueID valueId, byte value)
        {
            NativeWrapper.SetValueFromByte(valueId.IntPtr, value);
        }

        public void SetValue(ZWValueID valueId, int value)
        {
            NativeWrapper.SetValueFromInt(valueId.IntPtr, value);
        }

        public void SetValue(ZWValueID valueId, string value)
        {
            NativeWrapper.SetValueFromString(valueId.IntPtr, value);
        }

        public void SetValueListSelection(ZWValueID valueId, string value)
        {
            NativeWrapper.SetValueListSelection(valueId.IntPtr, value);
        }

        public string GetNodeName(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeName(homeId, nodeID));
        }

        public string GetNodeQueryStage(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeQueryStage(homeId, nodeID));
        }

        public string GetNodeLocation(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeLocation(homeId, nodeID));
        }

        public string GetNodeType(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeType(homeId, nodeID));
        }

        public byte GetNodeVersion(uint homeId, byte nodeID)
        {
            return NativeWrapper.GetNodeVersion(homeId, nodeID);
        }

        public string GetNodeManufacturerName(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeManufacturerName(homeId, nodeID));
        }

        public string GetNodeManufacturerId(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeManufacturerId(homeId, nodeID));
        }

        public string GetNodeProductName(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeProductName(homeId, nodeID));
        }

        public string GetNodeProductId(uint homeId, byte nodeID)
        {
            return Helper.ToString(NativeWrapper.GetNodeProductId(homeId, nodeID));
        }

        public string GetValueLabel(ZWValueID valueId)
        {
            return Helper.ToString(NativeWrapper.GetValueLabel(valueId.IntPtr));
        }

        public bool IsValueReadOnly(ZWValueID valueId)
        {
            return NativeWrapper.IsValueReadOnly(valueId.IntPtr);
        }

        public string GetValueHelp(ZWValueID valueId)
        {
            return Helper.ToString(NativeWrapper.GetValueHelp(valueId.IntPtr));
        }

        public string GetValueUnits(ZWValueID valueId)
        {
            return Helper.ToString(NativeWrapper.GetValueUnits(valueId.IntPtr));
        }

        public bool IsValueWriteOnly(ZWValueID valueId)
        {
            return NativeWrapper.IsValueWriteOnly(valueId.IntPtr);
        }

        public int GetValueMin(ZWValueID valueId)
        {
            return NativeWrapper.GetValueMin(valueId.IntPtr);
        }

        public int GetValueMax(ZWValueID valueId)
        {
            return NativeWrapper.GetValueMax(valueId.IntPtr);
        }

        public bool IsPolled(ZWValueID valueId)
        {
            return NativeWrapper.isPolled(valueId.IntPtr);
        }

        public bool GetValueListSelection(ZWValueID valueId, out string selected)
        {
            IntPtr value;
            bool result = NativeWrapper.GetValueListSelectionFromString(valueId.IntPtr, out value);
            selected = Helper.ToString(value);
            return result;
        }
        public bool AddNode(uint homeId, bool doSecurity = true)
        {
            return NativeWrapper.AddNode(homeId, doSecurity);
        }
        public bool RemoveNode(uint homeId)
        {
            return NativeWrapper.RemoveNode(homeId);
        }
        public void ResetController(uint homeId)
        {
            NativeWrapper.ResetController(homeId);
        }
    }
}