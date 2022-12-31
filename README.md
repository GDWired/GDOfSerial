<p align="center"><img src="https://user-images.githubusercontent.com/4105962/204136320-9e49eaf0-db2c-4335-b0dc-939e89770235.png" width="256"></p>

# <p align="center">GDOfSerial (Godot 3.5)</p>

openFramwork serial standalone for Godot, is a part of GDWired (https://github.com/GDWired) for macOS, Windows and Linux.

To compile it, just run `scons target=release` in the root folder. The Godot build dependencies must be installed first, you can find everything about it here https://docs.godotengine.org/en/stable/development/compiling/index.html.

## Demo

In the "demo" folder there is a sample project, after compiling the project you can open it with Godot 3.5.1. (You can also download a precompiled version of the plugin from the asset store or in the release section of github WIP) 

![Capture d’écran du 2022-12-30 17-24-40](https://user-images.githubusercontent.com/4105962/210091592-5f7041b2-74b6-4ad8-9f22-f04202043a87.png)

On the picture above, this is the demo project, if you press the "Send" button, the data on top will be sent to the first device found. The received data will be automatically written to the terminal. It is possible to get the data in hexa or string.

## API

``` gdscript

# Get device list
# @return the device list
get_device_list()

# Start communication with the specific device
# @param port_name the device port
# @param baudrate baudrate
# @return true if connected 
begin(port_name, baudrate)

# Start communication with the specific device (using specific configuration)
# Default configuration is SERIAL_8N1 (8 bits data, no parity, 1 stop bit)
# Available values:
#		SERIAL_5N1
#		SERIAL_6N1
#		SERIAL_7N1
#		SERIAL_8N1	// the default
#		SERIAL_5N2
#		SERIAL_6N2
#		SERIAL_7N2
#		SERIAL_8N2
#		SERIAL_5E1	// even parity
#		SERIAL_6E1
#		SERIAL_7E1
#		SERIAL_8E1
#		SERIAL_5E2
#		SERIAL_6E2
#		SERIAL_7E2
#		SERIAL_8E2
#		SERIAL_5O1	// odd parity
#		SERIAL_6O1
#		SERIAL_7O1
#		SERIAL_8O1
#		SERIAL_5O2
#		SERIAL_6O2
#		SERIAL_7O2
#		SERIAL_8O2
# @param port_name the device port
# @param baudrate baudrate
# @param config value from the enum (default: SERIAL_8N1)
# @return true if connected 
begin_with_config(clean_session, keep_alive)

# Return true if initialized
# @return true if initialized
is_initialized()

# Close connection
end()

# Return the number of bytes available to read
# @return the number of bytes available to read
available()

# Read one byte
# @return first byte
read()

# Read data as string
# @param length number of byte to read
# @return data as a string
read_string(length)

# Read raw data
# @param length number of byte to read
# @return raw data like [0x49, 0x4E, 0x49, 0x54]
read_bytes(length)

# Write string
# @param buffer the string to write
# @return the number of bytes written
print(buffer)

# Write string (with \n at the end)
# @param buffer the string to write
# @return the number of bytes written
println(buffer)

# Write raw data (hexa like: [0x49, 0x4E, 0x49, 0x54])
# @param buffer the raw data buffer
# @return the number of bytes written
write(buffer)

# Flush IN buffer
flush_in()

# Flush OUT buffer
flush_out()

# Flush IN/OUT buffers
flush()
````
