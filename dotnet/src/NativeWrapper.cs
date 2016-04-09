using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace OpenZWaveDotNet
{
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void OnNotificationCallback(IntPtr notification, IntPtr context);

    public class NativeWrapper
    {

        private const String  DLL = "libopenzwavewrapper";

        private const CallingConvention CC = CallingConvention.Cdecl;

        /*Options.h*/
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void CreateOptions(string configPath, string userPath, string commandLine);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool DestroyOptions();
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddOptionBool(string name, bool _default);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddOptionInt(string name, int _default);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddOptionString(string cname, string _default, bool append);

        /*Manager.h*/
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool Lock();
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void CreateManager();
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddDriver(string controllerPath);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddWatcher([MarshalAs(UnmanagedType.FunctionPtr)]OnNotificationCallback watcher, IntPtr context);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RemoveWatcher([MarshalAs(UnmanagedType.FunctionPtr)]OnNotificationCallback watcher, IntPtr context);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void WriteConfig(uint homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RemoveDriver(string controllerPath);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetControllerNodeId(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetSUCNodeId(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsPrimaryController(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsStaticUpdateController(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsBridgeController(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetLibraryVersion(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetLibraryTypeName(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static Int32 GetSendQueueCount(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void LogDriverStatistics(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetControllerInterfaceType(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetControllerPath(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static Int32 GetPollInterval();
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetPollInterval(Int32 milliseconds, bool bIntervalBetweenPolls);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool EnablePoll(IntPtr valueId, byte intensity = 1);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool DisablePoll(IntPtr valueId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool isPolled(IntPtr valueId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetPollIntensity(IntPtr valueId, byte intensity);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetPollIntensity(IntPtr valueId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RefreshNodeInfo(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RequestNodeState(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RequestNodeDynamic(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeListeningDevice(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeFrequentListeningDevice(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeBeamingDevice(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeRoutingDevice(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeSecurityDevice(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static UInt32 GetNodeMaxBaudRate(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNodeVersion(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNodeSecurity(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeZWavePlus(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNodeBasic(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNodeGeneric(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNodeSpecific(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeType(UInt32 homeId, byte nodeId);
        //public extern static UInt32 GetNodeNeighbors(UInt32 homeId, byte nodeId, byte** nodeNeighbors);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeManufacturerName(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeProductName(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeName(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeLocation(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeManufacturerId(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeProductType(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeProductId(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetNodeManufacturerName(UInt32 homeId, byte nodeId, string manufacturerName);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetNodeProductName(UInt32 homeId, byte nodeId, string productName);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetNodeName(UInt32 homeId, byte nodeId, string nodeName);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetNodeLocation(UInt32 homeId, byte nodeId, string location);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetNodeOn(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetNodeOff(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetNodeLevel(UInt32 homeId, byte nodeId, byte level);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeInfoReceived(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        //public extern static bool GetNodeClassInformation(UInt32 homeId, byte nodeId, byte commandClassId,string className, byte classVersion);
        public extern static bool IsNodeAwake(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsNodeFailed(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeQueryStage(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static UInt16 GetNodeDeviceType(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeDeviceTypeString(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNodeRole(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodeRoleString(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNodePlusType(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNodePlusTypeString(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetValueLabel(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetValueLabel(IntPtr id, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetValueUnits(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetValueUnits(IntPtr id, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetValueHelp(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetValueHelp(IntPtr id, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static Int32 GetValueMin(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static Int32 GetValueMax(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsValueReadOnly(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsValueWriteOnly(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsValueSet(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool IsValuePolled(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueAsBool(IntPtr id, out bool ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueAsByte(IntPtr id, out byte ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueAsFloat(IntPtr id, out float ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueAsInt(IntPtr id, out int ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueAsShort(IntPtr id, out short ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueAsString(IntPtr id, out IntPtr ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueAsRaw(IntPtr id, out byte ovalue, out byte olength);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueListSelectionFromString(IntPtr id, out IntPtr ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueListSelectionFromInt(IntPtr id, out int ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueListItems(IntPtr id, out IntPtr ovalue, ref int count);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetValueFloatPrecision(IntPtr id, out byte ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueFromBool(IntPtr id, bool value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueFromByte(IntPtr id, byte value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueFromFloat(IntPtr id, float value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueFromInt(IntPtr id, Int32 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueFromShort(IntPtr id, Int16 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueFromUByte(IntPtr id, byte value, byte length);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueFromString(IntPtr id, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetValueListSelection(IntPtr id, string selectedItem);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RefreshValue(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetChangeVerified(IntPtr id, bool verify);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool GetChangeVerified(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool PressButton(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool ReleaseButton(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNumSwitchPoints(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSwitchPoint(IntPtr id, byte hours, byte minutes, sbyte setback);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RemoveSwitchPoint(IntPtr id, byte hours, byte minutes);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void ClearSwitchPoints(IntPtr id);
        [DllImport(DLL, CallingConvention = CC)]
        //public extern static bool GetSwitchPoint(IntPtr id, byte idx, byte* ohours, byte* ominutes, int8* osetback);
        public extern static void SwitchAllOn(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SwitchAllOff(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetConfigParam(UInt32 homeId, byte nodeId, byte param, Int32 value, byte size = 2);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void RequestConfigParam(UInt32 homeId, byte nodeId, byte param);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void RequestAllConfigParams(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNumGroups(UInt32 homeId, byte nodeId);
        //public extern static UInt32 GetAssociations(UInt32 homeId, byte nodeId, byte groupIdx, byte** oassociations);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static UInt32 GetAssociationsFromInstance(UInt32 homeId, byte nodeId, byte groupIdx, IntPtr oassociations);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetMaxAssociations(UInt32 homeId, byte nodeId, byte groupIdx);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetGroupLabel(UInt32 homeId, byte nodeId, byte groupIdx);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void AddAssociation(UInt32 homeId, byte nodeId, byte groupIdx, byte targetNodeId, byte instance = 0x00);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void RemoveAssociation(UInt32 homeId, byte nodeId, byte groupIdx, byte targetNodeId, byte instance = 0x00);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void ResetController(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SoftReset(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool CancelControllerCommand(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void TestNetworkNode(UInt32 homeId, byte nodeId, UInt32 count);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void TestNetwork(UInt32 homeId, UInt32 count);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void HealNetworkNode(UInt32 homeId, byte nodeId, bool doRR);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void HealNetwork(UInt32 homeId, bool doRR);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddNode(UInt32 homeId, bool doSecurity = true);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RemoveNode(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RemoveFailedNode(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool HasNodeFailed(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RequestNodeNeighborUpdate(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AssignReturnRoute(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool DeleteAllReturnRoutes(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SendNodeInformation(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool CreateNewPrimary(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool ReceiveConfiguration(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool ReplaceFailedNode(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool TransferPrimaryRole(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RequestNetworkUpdate(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool ReplicationSend(UInt32 homeId, byte nodeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool CreateButton(UInt32 homeId, byte nodeId, byte buttonid);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool DeleteButton(UInt32 homeId, byte nodeId, byte buttonid);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNumScenes();
        //public extern static byte GetAllScenes(byte** sceneIds);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void RemoveAllScenes(UInt32 homeId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte CreateScene();
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RemoveScene(byte sceneId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueFromBool(byte sceneId, IntPtr valueId, bool value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueFromByte(byte sceneId, IntPtr valueId, byte value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueFromFloat(byte sceneId, IntPtr valueId, float value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueFromInt(byte sceneId, IntPtr valueId, Int32 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueFromShort(byte sceneId, IntPtr valueId, Int16 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueFromString(byte sceneId, IntPtr valueId, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueListSelectionFromString(byte sceneId, IntPtr valueId, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool AddSceneValueListSelectionFromInt(byte sceneId, IntPtr valueId, Int32 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool RemoveSceneValue(byte sceneId, IntPtr valueId);
        //public extern static int SceneGetValues(byte sceneId, vector<OpenZWave::ValueID>* ovalue);
        //public extern static bool SceneGetValueAsBool(byte sceneId, IntPtr valueId, bool* ovalue);
        //        public extern static bool SceneGetValueAsByte(byte sceneId, IntPtr valueId, byte* ovalue);
        //public extern static bool SceneGetValueAsFloat(byte sceneId, IntPtr valueId, float* ovalue);
        //        public extern static bool SceneGetValueAsInt(byte sceneId, IntPtr valueId, Int32* ovalue);
        //public extern static bool SceneGetValueAsShort(byte sceneId, IntPtr valueId, Int16* ovalue);
        //public extern static bool SceneGetValueAsString(byte sceneId, IntPtr valueId, string* ovalue);
        //public extern static bool GetValueListSelectionFromString(byte sceneId, IntPtr valueId, string* ovalue);
        //public extern static bool GetValueListSelectionFromInt(byte sceneId, IntPtr valueId, Int32* ovalue);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueFromBool(byte sceneId, IntPtr valueId, bool value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueFromByte(byte sceneId, IntPtr valueId, byte value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueFromFloat(byte sceneId, IntPtr valueId, float value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueFromInt(byte sceneId, IntPtr valueId, Int32 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueFromShort(byte sceneId, IntPtr valueId, Int16 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueFromString(byte sceneId, IntPtr valueId, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueListSelectionFromString(byte sceneId, IntPtr valueId, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SetSceneValueListSelectionFromInt(byte sceneId, IntPtr valueId, Int32 value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static string GetSceneLabel(byte sceneId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void SetSceneLabel(byte sceneId, string value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool SceneExists(byte sceneId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static bool ActivateScene(byte sceneId);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void GetDriverStatistics(UInt32 homeId, IntPtr data);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void GetNodeStatistics(UInt32 homeId, byte nodeId, IntPtr data);

        /*Notification.h*/
        [DllImport(DLL, CallingConvention = CC)]
        public extern static uint GetNotificationType(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static uint GetNotificationHomeId(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNotificationNodeId(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNotificationValueID(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNotificationGroupIdx(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNotificationEvent(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNotificationButtonId(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNotificationSceneId(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNotificationNotification(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetNotificationByte(IntPtr notification);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static IntPtr GetNotificationAsString(IntPtr notification);

        /*ValueID.h*/
        [DllImport(DLL, CallingConvention = CC)]
        public extern static uint GetValueHomeId(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetValueNodeId(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static Int32 GetValueGenre(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetValueCommandClassId(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetValueInstance(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static byte GetValueIndex(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static Int32 GetValueType(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static ulong GetValueId(IntPtr value);
        [DllImport(DLL, CallingConvention = CC)]
        public extern static void DeleteValue(IntPtr value);
    }
}