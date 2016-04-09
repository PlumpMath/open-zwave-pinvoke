using System;

namespace OpenZWaveDotNet
{
    public class ZWNotification
    {
        public enum Type
        {
            ValueAdded,
            ValueRemoved,
            ValueChanged,
            ValueRefreshed,
            Group,
            NodeNew,
            NodeAdded,
            NodeRemoved,
            NodeProtocolInfo,
            NodeNaming,
            NodeEvent,
            PollingDisabled,
            PollingEnabled,
            SceneEvent,
            CreateButton,
            DeleteButton,
            ButtonOn,
            ButtonOff,
            DriverReady,
            DriverFailed,
            DriverReset,
            EssentialNodeQueriesComplete,
            NodeQueriesComplete,
            AwakeNodesQueried,
            AllNodesQueriedSomeDead,
            AllNodesQueried,
            Notification,
            DriverRemoved,
            ControllerCommand,
            NodeReset
        };

        public enum Code
        {
            MsgCompletee,
			Timeout,
			NoOperation,
			Awake,
			Sleep,
			Dead,
			Alive
        };

        private Type NotificationType { get; set; }
        private byte NodeId { get; set; }
        private uint HomeId { get; set; }
        private ZWValueID ZWValueID { get; set; }
        private byte Byte { get; set; }
        private byte Event { get; set; }
        private Code NotificationCode { get; set; }

        internal ZWNotification(IntPtr notification)
        {
            NotificationType = (Type)NativeWrapper.GetNotificationType(notification);
            NodeId = NativeWrapper.GetNotificationNodeId(notification);
            HomeId = NativeWrapper.GetNotificationHomeId(notification);
            ZWValueID = new ZWValueID(NativeWrapper.GetNotificationValueID(notification));
            Byte = NativeWrapper.GetNotificationByte(notification);
            NotificationCode = (Code)Byte;

            if(NotificationType == Type.ControllerCommand)
                Event = NativeWrapper.GetNotificationEvent(notification);
        }

        public new Type GetType()
        {
            return NotificationType;
        }

        public byte GetNodeId()
        {
            return NodeId;
        }

        public byte GetByte()
        {
            return Byte;
        }

        public byte GetEvent()
        {
            return Event;
        }

        public Code GetCode()
        {
            return NotificationCode;
        }

        public uint GetHomeId()
        {
            return HomeId;
        }

        public ZWValueID GetValueID()
        {
            return ZWValueID;
        }
    }
}