using System;

namespace OpenZWaveDotNet
{
    public class ZWOptions
    {
        public void Create(string configPath, string userPath, string commandLine)
        {
            NativeWrapper.CreateOptions(configPath, userPath, commandLine);
        }

        public void AddOptionInt(string name, int _default)
        {
            NativeWrapper.AddOptionInt(name, _default);
        }

        public void Lock()
        {
            NativeWrapper.Lock();
        }
    }
}