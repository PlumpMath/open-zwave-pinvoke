#include <string>
#include <cstring>
#include <iterator> 
#include <algorithm>

#include "Manager.h"
#include "Options.h"
#include "Driver.h"
#include "Group.h"
#include "Notification.h"
#include "ValueID.h"

using namespace std;



#if defined (__GNUC__) && defined(__unix__)
#define PRINT_API __attribute__ ((__visibility__("default")))
#elif defined (WIN32)
#define PRINT_API __declspec(dllexport)
#endif

#define OPENZWAVE_EXPORT extern "C" PRINT_API

const char* toChar(string str) {
	char* copyStr = (char*) malloc(sizeof(char) * str.size() + 1);
	strcpy(copyStr, str.c_str());
	copyStr[str.size()] = '\0';
	return copyStr;
}

string* ToString(const char* value) {
	return new string(value);
}

/* Options.h */
OPENZWAVE_EXPORT void CreateOptions(const char* configPath, const char* userPath, const char* commandLine) { OpenZWave::Options::Create(string(configPath), string(userPath), string(commandLine)); }
OPENZWAVE_EXPORT bool DestroyOptions() { return OpenZWave::Options::Destroy(); }
OPENZWAVE_EXPORT bool AddOptionBool(const char* name, bool const defaultValue) { return OpenZWave::Options::Get()->AddOptionBool(string(name), defaultValue); }
OPENZWAVE_EXPORT bool AddOptionInt(const char* name, int32 const defaultValue) { return OpenZWave::Options::Get()->AddOptionInt(string(name), defaultValue); }
OPENZWAVE_EXPORT bool AddOptionString(const char* name, const char* defaultValue, bool const append) { return OpenZWave::Options::Get()->AddOptionString(string(name), defaultValue, append); }
OPENZWAVE_EXPORT bool Lock() { return OpenZWave::Options::Get()->Lock(); }

/* Manager.h */
OPENZWAVE_EXPORT void CreateManager() { OpenZWave::Manager::Create(); }
OPENZWAVE_EXPORT bool AddDriver(const char* controllerPath) { return OpenZWave::Manager::Get()->AddDriver(string(controllerPath)); }
OPENZWAVE_EXPORT bool AddWatcher(OpenZWave::Manager::pfnOnNotification_t watcher, void* context) { return OpenZWave::Manager::Get()->AddWatcher(watcher, context); }
OPENZWAVE_EXPORT bool RemoveWatcher(OpenZWave::Manager::pfnOnNotification_t watcher, void* context) { return OpenZWave::Manager::Get()->RemoveWatcher(watcher, context); }
OPENZWAVE_EXPORT void WriteConfig(uint32 homeId) { OpenZWave::Manager::Get()->WriteConfig(homeId); }

OPENZWAVE_EXPORT bool RemoveDriver(const char* controllerPath) { return OpenZWave::Manager::Get()->RemoveDriver(controllerPath); }
OPENZWAVE_EXPORT uint8 GetControllerNodeId(uint32 const homeId) { return OpenZWave::Manager::Get()->GetControllerNodeId(homeId); }
OPENZWAVE_EXPORT uint8 GetSUCNodeId(uint32 const homeId) { return OpenZWave::Manager::Get()->GetSUCNodeId(homeId); }
OPENZWAVE_EXPORT bool IsPrimaryController(uint32 const homeId) { return OpenZWave::Manager::Get()->IsPrimaryController(homeId); }
OPENZWAVE_EXPORT bool IsStaticUpdateController(uint32 const homeId) { return OpenZWave::Manager::Get()->IsStaticUpdateController(homeId); }
OPENZWAVE_EXPORT bool IsBridgeController(uint32 const homeId) { return OpenZWave::Manager::Get()->IsBridgeController(homeId); }
OPENZWAVE_EXPORT const char* GetLibraryVersion(uint32 const homeId) { return toChar(OpenZWave::Manager::Get()->GetLibraryVersion(homeId)); }
OPENZWAVE_EXPORT const char* GetLibraryTypeName(uint32 const homeId) { return toChar(OpenZWave::Manager::Get()->GetLibraryTypeName(homeId)); }
OPENZWAVE_EXPORT int32 GetSendQueueCount(uint32 const homeId) { return OpenZWave::Manager::Get()->GetSendQueueCount(homeId); }
OPENZWAVE_EXPORT void LogDriverStatistics(uint32 const homeId) { OpenZWave::Manager::Get()->LogDriverStatistics(homeId); }
OPENZWAVE_EXPORT OpenZWave::Driver::ControllerInterface* GetControllerInterfaceType(uint32 const homeId) { return new OpenZWave::Driver::ControllerInterface(OpenZWave::Manager::Get()->GetControllerInterfaceType(homeId)); }
OPENZWAVE_EXPORT const char* GetControllerPath(uint32 const homeId) { return toChar(OpenZWave::Manager::Get()->GetControllerPath(homeId)); }
OPENZWAVE_EXPORT int32 GetPollInterval() { return OpenZWave::Manager::Get()->GetPollInterval(); }
OPENZWAVE_EXPORT void SetPollInterval(int32 milliseconds, bool bIntervalBetweenPolls) { OpenZWave::Manager::Get()->SetPollInterval(milliseconds, bIntervalBetweenPolls); }
OPENZWAVE_EXPORT bool EnablePoll(OpenZWave::ValueID* valueId, uint8 const intensity = 1) { return OpenZWave::Manager::Get()->EnablePoll(*valueId, intensity); }
OPENZWAVE_EXPORT bool DisablePoll(OpenZWave::ValueID* valueId) { return OpenZWave::Manager::Get()->DisablePoll(*valueId); }
OPENZWAVE_EXPORT bool isPolled(OpenZWave::ValueID* valueId) { return OpenZWave::Manager::Get()->isPolled(*valueId); }
OPENZWAVE_EXPORT void SetPollIntensity(OpenZWave::ValueID* valueId, uint8 const intensity) { return OpenZWave::Manager::Get()->SetPollIntensity(*valueId, intensity); }
OPENZWAVE_EXPORT uint8 GetPollIntensity(OpenZWave::ValueID* valueId) { return OpenZWave::Manager::Get()->GetPollIntensity(*valueId); }
OPENZWAVE_EXPORT bool RefreshNodeInfo(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->RefreshNodeInfo(homeId, nodeId); }
OPENZWAVE_EXPORT bool RequestNodeState(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->RequestNodeState(homeId, nodeId); }
OPENZWAVE_EXPORT bool RequestNodeDynamic(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->RequestNodeDynamic(homeId, nodeId); }
OPENZWAVE_EXPORT bool IsNodeListeningDevice(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeListeningDevice(homeId, nodeId); }
OPENZWAVE_EXPORT bool IsNodeFrequentListeningDevice(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeFrequentListeningDevice(homeId, nodeId); }
OPENZWAVE_EXPORT bool IsNodeBeamingDevice(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeBeamingDevice(homeId, nodeId); }
OPENZWAVE_EXPORT bool IsNodeRoutingDevice(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeRoutingDevice(homeId, nodeId); }
OPENZWAVE_EXPORT bool IsNodeSecurityDevice(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeSecurityDevice(homeId, nodeId); }
OPENZWAVE_EXPORT uint32 GetNodeMaxBaudRate(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeMaxBaudRate(homeId, nodeId); }
OPENZWAVE_EXPORT uint8 GetNodeVersion(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeVersion(homeId, nodeId); }
OPENZWAVE_EXPORT uint8 GetNodeSecurity(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeSecurity(homeId, nodeId); }
OPENZWAVE_EXPORT bool IsNodeZWavePlus(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeZWavePlus(homeId, nodeId); }
OPENZWAVE_EXPORT uint8 GetNodeBasic(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeBasic(homeId, nodeId); }
OPENZWAVE_EXPORT uint8 GetNodeGeneric(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeGeneric(homeId, nodeId); }
OPENZWAVE_EXPORT uint8 GetNodeSpecific(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeSpecific(homeId, nodeId); }
OPENZWAVE_EXPORT const char* GetNodeType(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeType(homeId, nodeId)); }
OPENZWAVE_EXPORT uint32 GetNodeNeighbors(uint32 const homeId, uint8 const nodeId, uint8** nodeNeighbors) { return OpenZWave::Manager::Get()->GetNodeNeighbors(homeId, nodeId, nodeNeighbors); }
OPENZWAVE_EXPORT const char* GetNodeManufacturerName(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeManufacturerName(homeId, nodeId)); }
OPENZWAVE_EXPORT const char* GetNodeProductName(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeProductName(homeId, nodeId)); }
OPENZWAVE_EXPORT const char* GetNodeName(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeName(homeId, nodeId)); }
OPENZWAVE_EXPORT const char* GetNodeLocation(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeLocation(homeId, nodeId)); }
OPENZWAVE_EXPORT const char* GetNodeManufacturerId(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeManufacturerId(homeId, nodeId)); }
OPENZWAVE_EXPORT const char* GetNodeProductType(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeProductType(homeId, nodeId)); }
OPENZWAVE_EXPORT const char* GetNodeProductId(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeProductId(homeId, nodeId)); }
OPENZWAVE_EXPORT void SetNodeManufacturerName(uint32 const homeId, uint8 const nodeId, const char* manufacturerName) { return OpenZWave::Manager::Get()->SetNodeManufacturerName(homeId, nodeId, manufacturerName); }
OPENZWAVE_EXPORT void SetNodeProductName(uint32 const homeId, uint8 const nodeId, const char* productName) { return OpenZWave::Manager::Get()->SetNodeProductName(homeId, nodeId, productName); }
OPENZWAVE_EXPORT void SetNodeName(uint32 const homeId, uint8 const nodeId, const char* nodeName) { return OpenZWave::Manager::Get()->SetNodeProductName(homeId, nodeId, nodeName); }
OPENZWAVE_EXPORT void SetNodeLocation(uint32 const homeId, uint8 const nodeId, const char* nodeName) { return OpenZWave::Manager::Get()->SetNodeProductName(homeId, nodeId, nodeName); }
OPENZWAVE_EXPORT void SetNodeOn(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->SetNodeOn(homeId, nodeId); }
OPENZWAVE_EXPORT void SetNodeOff(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->SetNodeOff(homeId, nodeId); }
OPENZWAVE_EXPORT void SetNodeLevel(uint32 const homeId, uint8 const nodeId, uint8 const level) { return OpenZWave::Manager::Get()->SetNodeLevel(homeId, nodeId, level); }
OPENZWAVE_EXPORT bool IsNodeInfoReceived(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeInfoReceived(homeId, nodeId); }
OPENZWAVE_EXPORT bool GetNodeClassInformation(uint32 const homeId, uint8 const nodeId, uint8 const commandClassId, const char* className = NULL, uint8 *classVersion = NULL) { return OpenZWave::Manager::Get()->GetNodeClassInformation(homeId, nodeId, commandClassId, ToString(className), classVersion); }
OPENZWAVE_EXPORT bool IsNodeAwake(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeAwake(homeId, nodeId); }
OPENZWAVE_EXPORT bool IsNodeFailed(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->IsNodeFailed(homeId, nodeId); }
OPENZWAVE_EXPORT const char* GetNodeQueryStage(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeQueryStage(homeId, nodeId)); }
OPENZWAVE_EXPORT uint16 GetNodeDeviceType(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeDeviceType(homeId, nodeId); }
OPENZWAVE_EXPORT const char* GetNodeDeviceTypeString(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeDeviceTypeString(homeId, nodeId)); }
OPENZWAVE_EXPORT uint8 GetNodeRole(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodeRole(homeId, nodeId); }
OPENZWAVE_EXPORT const char* GetNodeRoleString(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodeRoleString(homeId, nodeId)); }
OPENZWAVE_EXPORT uint8 GetNodePlusType(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNodePlusType(homeId, nodeId); }
OPENZWAVE_EXPORT const char* GetNodePlusTypeString(uint32 const homeId, uint8 const nodeId) { return toChar(OpenZWave::Manager::Get()->GetNodePlusTypeString(homeId, nodeId)); }
OPENZWAVE_EXPORT const char* GetValueLabel(OpenZWave::ValueID* id) { return toChar(OpenZWave::Manager::Get()->GetValueLabel(*id)); }
OPENZWAVE_EXPORT void SetValueLabel(OpenZWave::ValueID* id, const char* value) { OpenZWave::Manager::Get()->SetValueLabel(*id, value); }
OPENZWAVE_EXPORT const char* GetValueUnits(OpenZWave::ValueID* id) { return toChar(OpenZWave::Manager::Get()->GetValueUnits(*id)); }
OPENZWAVE_EXPORT void SetValueUnits(OpenZWave::ValueID* id, const char* value) { OpenZWave::Manager::Get()->SetValueUnits(*id, value); }
OPENZWAVE_EXPORT const char* GetValueHelp(OpenZWave::ValueID* id) { return toChar(OpenZWave::Manager::Get()->GetValueHelp(*id)); }
OPENZWAVE_EXPORT void SetValueHelp(OpenZWave::ValueID* id, const char* value) { OpenZWave::Manager::Get()->SetValueHelp(*id, value); }
OPENZWAVE_EXPORT int32 GetValueMin(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->GetValueMin(*id); }
OPENZWAVE_EXPORT int32 GetValueMax(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->GetValueMax(*id); }
OPENZWAVE_EXPORT bool IsValueReadOnly(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->IsValueReadOnly(*id); }
OPENZWAVE_EXPORT bool IsValueWriteOnly(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->IsValueWriteOnly(*id); }
OPENZWAVE_EXPORT bool IsValueSet(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->IsValueSet(*id); }
OPENZWAVE_EXPORT bool IsValuePolled(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->IsValuePolled(*id); }
OPENZWAVE_EXPORT bool GetValueAsBool(OpenZWave::ValueID* id, bool* ovalue) { return OpenZWave::Manager::Get()->GetValueAsBool(*id, ovalue); }
OPENZWAVE_EXPORT bool GetValueAsByte(OpenZWave::ValueID* id, uint8* ovalue) { return OpenZWave::Manager::Get()->GetValueAsByte(*id, ovalue); }
OPENZWAVE_EXPORT bool GetValueAsFloat(OpenZWave::ValueID* id, float* ovalue) { return OpenZWave::Manager::Get()->GetValueAsFloat(*id, ovalue); }
OPENZWAVE_EXPORT bool GetValueAsInt(OpenZWave::ValueID* id, int32* ovalue) { return OpenZWave::Manager::Get()->GetValueAsInt(*id, ovalue); }
OPENZWAVE_EXPORT bool GetValueAsShort(OpenZWave::ValueID* id, int16* ovalue) { return OpenZWave::Manager::Get()->GetValueAsShort(*id, ovalue); }
OPENZWAVE_EXPORT bool GetValueAsString(OpenZWave::ValueID* id, const char** ovalue) 
{ 
	string *str = new string();
	bool result = OpenZWave::Manager::Get()->GetValueAsString(*id, str);
	*ovalue = toChar(*str);
	delete str;
	return result;
}
OPENZWAVE_EXPORT bool GetValueAsRaw(OpenZWave::ValueID* id, uint8** ovalue, uint8* olength) { return OpenZWave::Manager::Get()->GetValueAsRaw(*id, ovalue, olength); }
OPENZWAVE_EXPORT bool GetValueListSelectionFromString(OpenZWave::ValueID* id, const char** ovalue) 
{ 
	string *str = new string();
	bool result = OpenZWave::Manager::Get()->GetValueListSelection(*id, str);
	*ovalue = toChar(*str);
	delete str;
	return result;
}
OPENZWAVE_EXPORT bool GetValueListSelectionFromInt(OpenZWave::ValueID* id, int32* ovalue) { return OpenZWave::Manager::Get()->GetValueListSelection(*id, ovalue); }
OPENZWAVE_EXPORT bool GetValueListItems(OpenZWave::ValueID* id, char*** result, int32* count)
{
	vector<string> *vec = new vector<string>();
	if (!OpenZWave::Manager::Get()->GetValueListItems(*id, vec))
		return false;

	*count = vec->size();
	*result = (char**) malloc(sizeof(char*) * (*count));
	for (size_t i = 0; i < *count; i++) {
		string str = (*vec)[i];
		(*result)[i] = (char*) malloc(sizeof(char) * str.size() + 1);
		strcpy((*result)[i], str.c_str());
	}

	delete vec;

	return true;
}
OPENZWAVE_EXPORT bool GetValueFloatPrecision(OpenZWave::ValueID* id, uint8* ovalue) { return OpenZWave::Manager::Get()->GetValueFloatPrecision(*id, ovalue); }
OPENZWAVE_EXPORT bool SetValueFromBool(OpenZWave::ValueID* id, bool const value) { return OpenZWave::Manager::Get()->SetValue(*id, value); }
OPENZWAVE_EXPORT bool SetValueFromByte(OpenZWave::ValueID* id, uint8 const value) { return OpenZWave::Manager::Get()->SetValue(*id, value); }
OPENZWAVE_EXPORT bool SetValueFromFloat(OpenZWave::ValueID* id, float const value) { return OpenZWave::Manager::Get()->SetValue(*id, value); }
OPENZWAVE_EXPORT bool SetValueFromInt(OpenZWave::ValueID* id, int32 const value) { return OpenZWave::Manager::Get()->SetValue(*id, value); }
OPENZWAVE_EXPORT bool SetValueFromShort(OpenZWave::ValueID* id, int16 const value) { return OpenZWave::Manager::Get()->SetValue(*id, value); }
OPENZWAVE_EXPORT bool SetValueFromUByte(OpenZWave::ValueID* id, uint8 const* value, uint8 const length) { return OpenZWave::Manager::Get()->SetValue(*id, value, length); }
OPENZWAVE_EXPORT bool SetValueFromString(OpenZWave::ValueID* id, const char* value) { return OpenZWave::Manager::Get()->SetValue(*id, value); }
OPENZWAVE_EXPORT bool SetValueListSelection(OpenZWave::ValueID* id, const char* selectedItem) { return OpenZWave::Manager::Get()->SetValueListSelection(*id, selectedItem); }
OPENZWAVE_EXPORT bool RefreshValue(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->RefreshValue(*id); }
OPENZWAVE_EXPORT void SetChangeVerified(OpenZWave::ValueID* id, bool verify) { return OpenZWave::Manager::Get()->SetChangeVerified(*id, verify); }
OPENZWAVE_EXPORT bool GetChangeVerified(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->GetChangeVerified(*id); }
OPENZWAVE_EXPORT bool PressButton(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->PressButton(*id); }
OPENZWAVE_EXPORT bool ReleaseButton(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->ReleaseButton(*id); }
OPENZWAVE_EXPORT uint8 GetNumSwitchPoints(OpenZWave::ValueID* id) { return OpenZWave::Manager::Get()->GetNumSwitchPoints(*id); }
OPENZWAVE_EXPORT bool SetSwitchPoint(OpenZWave::ValueID* id, uint8 const hours, uint8 const minutes, int8 const setback) { return OpenZWave::Manager::Get()->SetSwitchPoint(*id, hours, minutes, setback); }
OPENZWAVE_EXPORT bool RemoveSwitchPoint(OpenZWave::ValueID* id, uint8 const hours, uint8 const minutes) { return OpenZWave::Manager::Get()->RemoveSwitchPoint(*id, hours, minutes); }
OPENZWAVE_EXPORT void ClearSwitchPoints(OpenZWave::ValueID* id) { OpenZWave::Manager::Get()->ClearSwitchPoints(*id); }
OPENZWAVE_EXPORT bool GetSwitchPoint(OpenZWave::ValueID* id, uint8 const idx, uint8* ohours, uint8* ominutes, int8* osetback) { return OpenZWave::Manager::Get()->GetSwitchPoint(*id, idx, ohours, ominutes, osetback); }
OPENZWAVE_EXPORT void SwitchAllOn(uint32 const homeId) { OpenZWave::Manager::Get()->SwitchAllOn(homeId); }
OPENZWAVE_EXPORT void SwitchAllOff(uint32 const homeId) { OpenZWave::Manager::Get()->SwitchAllOff(homeId); }
OPENZWAVE_EXPORT bool SetConfigParam(uint32 const homeId, uint8 const nodeId, uint8 const param, int32 value, uint8 const size = 2) { return OpenZWave::Manager::Get()->SetConfigParam(homeId, nodeId, param, value, size); }
OPENZWAVE_EXPORT void RequestConfigParam(uint32 const homeId, uint8 const nodeId, uint8 const param) { return OpenZWave::Manager::Get()->RequestConfigParam(homeId, nodeId, param); }
OPENZWAVE_EXPORT void RequestAllConfigParams(uint32 const homeId, uint8 const nodeId) { OpenZWave::Manager::Get()->RequestAllConfigParams(homeId, nodeId); }
OPENZWAVE_EXPORT uint8 GetNumGroups(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->GetNumGroups(homeId, nodeId); }
OPENZWAVE_EXPORT uint32 GetAssociations(uint32 const homeId, uint8 const nodeId, uint8 const groupIdx, uint8** oassociations) { return OpenZWave::Manager::Get()->GetAssociations(homeId, nodeId, groupIdx, oassociations); }
OPENZWAVE_EXPORT uint32 GetAssociationsFromInstance(uint32 const homeId, uint8 const nodeId, uint8 const groupIdx, OpenZWave::InstanceAssociation** oassociations) { return OpenZWave::Manager::Get()->GetAssociations(homeId, nodeId, groupIdx, oassociations); }
OPENZWAVE_EXPORT uint8 GetMaxAssociations(uint32 const homeId, uint8 const nodeId, uint8 const groupIdx) { return OpenZWave::Manager::Get()->GetMaxAssociations(homeId, nodeId, groupIdx); }
OPENZWAVE_EXPORT const char* GetGroupLabel(uint32 const homeId, uint8 const nodeId, uint8 const groupIdx) { return toChar(OpenZWave::Manager::Get()->GetGroupLabel(homeId, nodeId, groupIdx)); }
OPENZWAVE_EXPORT void AddAssociation(uint32 const homeId, uint8 const nodeId, uint8 const groupIdx, uint8 const targetNodeId, uint8 const instance = 0x00) { OpenZWave::Manager::Get()->AddAssociation(homeId, nodeId, groupIdx, targetNodeId, instance); }
OPENZWAVE_EXPORT void RemoveAssociation(uint32 const homeId, uint8 const nodeId, uint8 const groupIdx, uint8 const targetNodeId, uint8 const instance = 0x00) { OpenZWave::Manager::Get()->RemoveAssociation(homeId, nodeId, groupIdx, instance); }
OPENZWAVE_EXPORT void ResetController(uint32 const homeId) { OpenZWave::Manager::Get()->ResetController(homeId); }
OPENZWAVE_EXPORT void SoftReset(uint32 const homeId) { OpenZWave::Manager::Get()->SoftReset(homeId); }
OPENZWAVE_EXPORT bool CancelControllerCommand(uint32 const homeId){return OpenZWave::Manager::Get()->CancelControllerCommand(homeId);}
OPENZWAVE_EXPORT void TestNetworkNode(uint32 const homeId, uint8 const nodeId, uint32 const count) { OpenZWave::Manager::Get()->TestNetworkNode(homeId, nodeId, count); }
OPENZWAVE_EXPORT void TestNetwork(uint32 const homeId, uint32 const count) { OpenZWave::Manager::Get()->TestNetwork(homeId, count); }
OPENZWAVE_EXPORT void HealNetworkNode(uint32 const homeId, uint8 const nodeId, bool doRR) { OpenZWave::Manager::Get()->HealNetworkNode(homeId, nodeId, doRR); }
OPENZWAVE_EXPORT void HealNetwork(uint32 const homeId, bool doRR) { OpenZWave::Manager::Get()->HealNetwork(homeId, doRR); }
OPENZWAVE_EXPORT bool AddNode(uint32 const homeId, bool doSecurity = true) { return OpenZWave::Manager::Get()->AddNode(homeId); }
OPENZWAVE_EXPORT bool RemoveNode(uint32 const homeId) { return OpenZWave::Manager::Get()->RemoveNode(homeId); }
OPENZWAVE_EXPORT bool RemoveFailedNode(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->RemoveFailedNode(homeId, nodeId); }
OPENZWAVE_EXPORT bool HasNodeFailed(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->HasNodeFailed(homeId, nodeId); }
OPENZWAVE_EXPORT bool RequestNodeNeighborUpdate(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->RequestNodeNeighborUpdate(homeId, nodeId); }
OPENZWAVE_EXPORT bool AssignReturnRoute(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->AssignReturnRoute(homeId, nodeId); }
OPENZWAVE_EXPORT bool DeleteAllReturnRoutes(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->DeleteAllReturnRoutes(homeId, nodeId); }
OPENZWAVE_EXPORT bool SendNodeInformation(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->SendNodeInformation(homeId, nodeId); }
OPENZWAVE_EXPORT bool CreateNewPrimary(uint32 const homeId) { return OpenZWave::Manager::Get()->CreateNewPrimary(homeId); }
OPENZWAVE_EXPORT bool ReceiveConfiguration(uint32 const homeId) { return OpenZWave::Manager::Get()->ReceiveConfiguration(homeId); }
OPENZWAVE_EXPORT bool ReplaceFailedNode(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->ReplaceFailedNode(homeId, nodeId); }
OPENZWAVE_EXPORT bool TransferPrimaryRole(uint32 const homeId) { return OpenZWave::Manager::Get()->TransferPrimaryRole(homeId); }
OPENZWAVE_EXPORT bool RequestNetworkUpdate(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->RequestNetworkUpdate(homeId, nodeId); }
OPENZWAVE_EXPORT bool ReplicationSend(uint32 const homeId, uint8 const nodeId) { return OpenZWave::Manager::Get()->ReplicationSend(homeId, nodeId); }
OPENZWAVE_EXPORT bool CreateButton(uint32 const homeId, uint8 const nodeId, uint8 const buttonid) { return OpenZWave::Manager::Get()->CreateButton(homeId, nodeId, buttonid); }
OPENZWAVE_EXPORT bool DeleteButton(uint32 const homeId, uint8 const nodeId, uint8 const buttonid) { return OpenZWave::Manager::Get()->DeleteButton(homeId, nodeId, buttonid); }
OPENZWAVE_EXPORT uint8 GetNumScenes() { return OpenZWave::Manager::Get()->GetNumScenes(); }
OPENZWAVE_EXPORT uint8 GetAllScenes(uint8** sceneIds) { return OpenZWave::Manager::Get()->GetAllScenes(sceneIds); }
OPENZWAVE_EXPORT void RemoveAllScenes(uint32 const homeId) { OpenZWave::Manager::Get()->RemoveAllScenes(homeId); }
OPENZWAVE_EXPORT uint8 CreateScene() { return OpenZWave::Manager::Get()->CreateScene(); }
OPENZWAVE_EXPORT bool RemoveScene(uint8 const sceneId) { return OpenZWave::Manager::Get()->RemoveScene(sceneId); }
OPENZWAVE_EXPORT bool AddSceneValueFromBool(uint8 const sceneId, OpenZWave::ValueID* valueId, bool const value) { return OpenZWave::Manager::Get()->AddSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool AddSceneValueFromByte(uint8 const sceneId, OpenZWave::ValueID* valueId, uint8 const value) { return OpenZWave::Manager::Get()->AddSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool AddSceneValueFromFloat(uint8 const sceneId, OpenZWave::ValueID* valueId, float const value) { return OpenZWave::Manager::Get()->AddSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool AddSceneValueFromInt(uint8 const sceneId, OpenZWave::ValueID* valueId, int32 const value) { return OpenZWave::Manager::Get()->AddSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool AddSceneValueFromShort(uint8 const sceneId, OpenZWave::ValueID* valueId, int16 const value) { return OpenZWave::Manager::Get()->AddSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool AddSceneValueFromString(uint8 const sceneId, OpenZWave::ValueID* valueId, const char* value) { return OpenZWave::Manager::Get()->AddSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool AddSceneValueListSelectionFromString(uint8 const sceneId, OpenZWave::ValueID* valueId, const char* value) { return OpenZWave::Manager::Get()->AddSceneValueListSelection(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool AddSceneValueListSelectionFromInt(uint8 const sceneId, OpenZWave::ValueID* valueId, int32 const value) { return OpenZWave::Manager::Get()->AddSceneValueListSelection(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool RemoveSceneValue(uint8 const sceneId, OpenZWave::ValueID*valueId) { return OpenZWave::Manager::Get()->RemoveSceneValue(sceneId, *valueId); }
OPENZWAVE_EXPORT int SceneGetValues(uint8 const sceneId, vector<OpenZWave::ValueID>* ovalue) { return OpenZWave::Manager::Get()->SceneGetValues(sceneId, ovalue); }
OPENZWAVE_EXPORT bool SceneGetValueAsBool(uint8 const sceneId, OpenZWave::ValueID* valueId, bool* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueAsBool(sceneId, *valueId, ovalue); }
OPENZWAVE_EXPORT bool SceneGetValueAsByte(uint8 const sceneId, OpenZWave::ValueID* valueId, uint8* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueAsByte(sceneId, *valueId, ovalue); }
OPENZWAVE_EXPORT bool SceneGetValueAsFloat(uint8 const sceneId, OpenZWave::ValueID* valueId, float* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueAsFloat(sceneId, *valueId, ovalue); }
OPENZWAVE_EXPORT bool SceneGetValueAsInt(uint8 const sceneId, OpenZWave::ValueID* valueId, int32* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueAsInt(sceneId, *valueId, ovalue); }
OPENZWAVE_EXPORT bool SceneGetValueAsShort(uint8 const sceneId, OpenZWave::ValueID* valueId, int16* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueAsShort(sceneId, *valueId, ovalue); }
OPENZWAVE_EXPORT bool SceneGetValueAsString(uint8 const sceneId, OpenZWave::ValueID* valueId, const char* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueAsString(sceneId, *valueId, ToString(ovalue)); }
OPENZWAVE_EXPORT bool SceneGetValueListSelectionFromString(uint8 const sceneId, OpenZWave::ValueID* valueId, const char* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueListSelection(sceneId, *valueId, ToString(ovalue)); }
OPENZWAVE_EXPORT bool SceneGetValueListSelectionFromInt(uint8 const sceneId, OpenZWave::ValueID* valueId, int32* ovalue) { return OpenZWave::Manager::Get()->SceneGetValueListSelection(sceneId, *valueId, ovalue); }
OPENZWAVE_EXPORT bool SetSceneValueFromBool(uint8 const sceneId, OpenZWave::ValueID* valueId, bool const value) { return OpenZWave::Manager::Get()->SetSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool SetSceneValueFromByte(uint8 const sceneId, OpenZWave::ValueID* valueId, uint8 const value) { return OpenZWave::Manager::Get()->SetSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool SetSceneValueFromFloat(uint8 const sceneId, OpenZWave::ValueID* valueId, float const value) { return OpenZWave::Manager::Get()->SetSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool SetSceneValueFromInt(uint8 const sceneId, OpenZWave::ValueID* valueId, int32 const value) { return OpenZWave::Manager::Get()->SetSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool SetSceneValueFromShort(uint8 const sceneId, OpenZWave::ValueID* valueId, int16 const value) { return OpenZWave::Manager::Get()->SetSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool SetSceneValueFromString(uint8 const sceneId, OpenZWave::ValueID* valueId, const char* value) { return OpenZWave::Manager::Get()->SetSceneValue(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool SetSceneValueListSelectionFromString(uint8 const sceneId, OpenZWave::ValueID* valueId, const char* value) { return OpenZWave::Manager::Get()->SetSceneValueListSelection(sceneId, *valueId, value); }
OPENZWAVE_EXPORT bool SetSceneValueListSelectionFromInt(uint8 const sceneId, OpenZWave::ValueID* valueId, int32 const value) { return OpenZWave::Manager::Get()->SetSceneValueListSelection(sceneId, *valueId, value); }
OPENZWAVE_EXPORT const char* GetSceneLabel(uint8 const sceneId) { return toChar(OpenZWave::Manager::Get()->GetSceneLabel(sceneId)); }
OPENZWAVE_EXPORT void SetSceneLabel(uint8 const sceneId, const char* value) { OpenZWave::Manager::Get()->SetSceneLabel(sceneId, value); }
OPENZWAVE_EXPORT bool SceneExists(uint8 const sceneId) { return OpenZWave::Manager::Get()->SceneExists(sceneId); }
OPENZWAVE_EXPORT bool ActivateScene(uint8 const sceneId) { return OpenZWave::Manager::Get()->ActivateScene(sceneId); }
OPENZWAVE_EXPORT void GetDriverStatistics(uint32 const homeId, OpenZWave::Driver::DriverData* data) { OpenZWave::Manager::Get()->GetDriverStatistics(homeId, data); }
OPENZWAVE_EXPORT void GetNodeStatistics(uint32 const homeId, uint8 const nodeId, OpenZWave::Node::NodeData* data) { OpenZWave::Manager::Get()->GetNodeStatistics(homeId, nodeId, data); }

/*Notification.h*/
OPENZWAVE_EXPORT uint32 GetNotificationType(OpenZWave::Notification* notification) { return notification->GetType(); }
OPENZWAVE_EXPORT uint32 GetNotificationHomeId(OpenZWave::Notification* notification) { return notification->GetHomeId(); }
OPENZWAVE_EXPORT uint8 GetNotificationNodeId(OpenZWave::Notification* notification) { return notification->GetNodeId(); }
OPENZWAVE_EXPORT OpenZWave::ValueID* GetNotificationValueID(OpenZWave::Notification* notification) { return new OpenZWave::ValueID(notification->GetValueID()); }
OPENZWAVE_EXPORT uint8 GetNotificationGroupIdx(OpenZWave::Notification* notification) { return notification->GetGroupIdx(); }
OPENZWAVE_EXPORT uint8 GetNotificationEvent(OpenZWave::Notification* notification) { return notification->GetEvent(); }
OPENZWAVE_EXPORT uint8 GetNotificationButtonId(OpenZWave::Notification* notification) { return notification->GetButtonId(); }
OPENZWAVE_EXPORT uint8 GetNotificationSceneId(OpenZWave::Notification* notification) { return notification->GetSceneId(); }
OPENZWAVE_EXPORT uint8 GetNotificationNotification(OpenZWave::Notification* notification) { return notification->GetNotification(); }
OPENZWAVE_EXPORT uint8 GetNotificationByte(OpenZWave::Notification* notification) { return notification->GetByte(); }
OPENZWAVE_EXPORT const char* GetNotificationAsString(OpenZWave::Notification* notification) { return toChar(notification->GetAsString()); }

/*ValueID.h*/
OPENZWAVE_EXPORT uint32 GetValueHomeId(OpenZWave::ValueID* value) { return value->GetHomeId(); }
OPENZWAVE_EXPORT uint8 GetValueNodeId(OpenZWave::ValueID* value) { return value->GetNodeId(); }
OPENZWAVE_EXPORT uint32 GetValueGenre(OpenZWave::ValueID* value) { return value->GetGenre(); }
OPENZWAVE_EXPORT uint8 GetValueCommandClassId(OpenZWave::ValueID* value) { return value->GetCommandClassId(); }
OPENZWAVE_EXPORT uint8 GetValueInstance(OpenZWave::ValueID* value) { return value->GetInstance(); }
OPENZWAVE_EXPORT uint8 GetValueIndex(OpenZWave::ValueID* value) { return value->GetIndex(); }
OPENZWAVE_EXPORT uint32 GetValueType(OpenZWave::ValueID* value) { return value->GetType(); }
OPENZWAVE_EXPORT uint64 GetValueId(OpenZWave::ValueID* value) { return value->GetId(); }
OPENZWAVE_EXPORT void DeleteValue(OpenZWave::ValueID* value) { delete value; }

/*Memory*/
OPENZWAVE_EXPORT void Free(void* ptr) { free(ptr); }