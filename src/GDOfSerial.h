#ifndef GDOFSERIAL
#define GDOFSERIAL

#include <Godot.hpp>
#include <Node.hpp>
#include <ofSerial.h>

using namespace godot;

/**
 * Arduino API
 * 
 * if(Serial) -> is_initialized
 * availableForWrite() -> impossible ?
 * find() -> ok
 * findUntil() -> ok
 * 
 * begin() -> begin, begin_with_config
 * available() -> ok
 * end() -> ok
 * setTimeout() -> ok
 * flush() -> flush, flush_in, flush_out
 * 
 * parseFloat() -> useless
 * parseInt() -> useless
 * 
 * write() -> ok
 * print() -> ok
 * println() -> ok
 * 
 * peek() -> impossible ?
 * read() -> ok
 * readBytes() -> ok
 * readBytesUntil() -> ok
 * readString() -> ok
 * readStringUntil() -> ok
 * 
 * serialEvent() -> not applicable
 */

namespace godot {

	enum OfSerialConfig {
		SERIAL_5N1,
		SERIAL_6N1,
		SERIAL_7N1,
		SERIAL_8N1,	// the default
		SERIAL_5N2,
		SERIAL_6N2,
		SERIAL_7N2,
		SERIAL_8N2,
		SERIAL_5E1,	// even parity
		SERIAL_6E1,
		SERIAL_7E1,
		SERIAL_8E1,
		SERIAL_5E2,
		SERIAL_6E2,
		SERIAL_7E2,
		SERIAL_8E2,
		SERIAL_5O1,	// odd parity
		SERIAL_6O1,
		SERIAL_7O1,
		SERIAL_8O1,
		SERIAL_5O2,
		SERIAL_6O2,
		SERIAL_7O2,
		SERIAL_8O2
	};

	class GDOfSerial : public Node {
		GODOT_CLASS(GDOfSerial, Node)

		// Private attributs
		private:

			/**
			 * The maximum milliseconds to wait for serial data. It defaults to 1000 milliseconds.
			 */
			int m_timeout;

			/**
			 * The serial holder.
			 */
			ofSerial m_serial;
		
		// Private methods
		private:

			//###############################################################
			//	Internals
			//###############################################################

			//###############################################################
			//	Wrapped methods
			//###############################################################

			/**
			 * This lists all the available serial devices to the console or
			 * standard output.
			 *
			 * On OSX and Linux this will return all the devices listed in /dev tty
			 * and cu, so you might want to compare it against a list of devices that
			 * you're expecting if you want to use it to dynamically connect to a
			 * device.
			 */
			void list_devices();

			/**
			 * Returns a list of ofSerialDeviceInfo instances with the
			 * devicePath, deviceName, deviceID set.
			 * @return list of serial names (the index can be used with begin(index, baudrate))
			 */
			Array get_device_list();

			/**
			 * Opens the serial port, with the given name and baud rate.
			 * @param p_port_name the port name
			 * @param p_baudrate the baud rate
			 * @return true if the device is initialized
			 */
			bool begin(const String p_port_name, const int p_baudrate);

			/**
			 * Opens the serial port, with the given name and baud rate.
			 * @param p_port_name the port name
			 * @param p_baudrate the baud rate
			 * @param p_config sets data, parity, and stop bits
			 * @return true if the device is initialized
			 */
			bool begin_with_config(const String p_port_name, const int p_baudrate, const int p_config);

			/**
			 * Return true if the device is initialized.
			 * @return true if the device is initialized
			 */
			bool is_initialized() const;

			/**
			 * Closes the connection to the serial device.
			 */
			void end();

			/**
			 * The available method is useful when you want to know how many bytes
			 * are available in the serial port. For instance, if you only want to
			 * read when there are 8 bytes waiting for you, you would do:
			 *
			 * if(device.available() > 8) {
			 *	 device.readData(buffer, 8);
			 * }
			 *
			 * This is useful when you know how int a complete message from a device
			 * is going to be.
			 * @return the number of bytes available to read
			 */
			int available();

			/**
			 * Reads incoming serial data.
			 * @return a first byte read from the serial buffer
			 */
			int read();

			/**
			 * Reads incoming serial data.
			 * @param p_lenght number of bytes to read
			 * @return a String read from the serial buffer
			 */
			String read_string(const int p_lenght);

			/**
			 * Reads incoming serial data.
			 * @param p_lenght number of bytes to read
			 * @return a PoolByteArray read from the serial buffer
			 */
			PoolByteArray read_bytes(const int p_lenght);

			/**
			 * This writes string into the serial buffer from the buffer pointer passed in
			 * @param p_buffer the buffer to write
			 * @return the number of bytes written (or OF_SERIAL_ERROR)
			 */
			int print(const String p_buffer);

			/**
			 * This writes string into the serial buffer from the buffer pointer passed in (add '\n' at the end)
			 * @param p_buffer the buffer to write
			 * @return the number of bytes written (or OF_SERIAL_ERROR)
			 */
			int println(const String p_buffer);

			/**
			 * This writes bytes into the serial buffer from the buffer pointer passed in (add '\n' at the end)
			 * @param p_buffer the buffer to write
			 * @return the number of bytes written (or OF_SERIAL_ERROR)
			 */
			int write(const PoolByteArray p_buffer);

			/**
			 * Clears data from the incoming data buffer.
			 * Any data in the cleared buffers is discarded.
			 */
			void flush_in();
			
			/**
			 * Clears data from the outgoing data buffer.
			 * Any data in the cleared buffers is discarded.
			 */
			void flush_out();
			
			/**
			 * Clears data from both of the serial buffers.
			 * Any data in the cleared buffers is discarded.
			 */
			void flush();

			/**
			 * Drain is only available on OSX and Linux and is very similar to
			 * flush(), but blocks until all the data has been written to or read
			 * from the serial port.
			 */
			//void drain();

		// Public methods
		public:

			//###############################################################
			//	Constructor
			//###############################################################

			/**
			 * Constructor
			 */
			GDOfSerial();

			/**
			 * Destructor
			 */
			~GDOfSerial();

			//###############################################################
			//	Godot methods
			//###############################################################

			/**
			 * Bind methods, signals etc.
			 */
			static void _register_methods();

			/**
			 * Init the class
			 */
			void _init();

			//###############################################################
			//	Callbacks
			//###############################################################

			//###############################################################
			//	Emit handlers
			//###############################################################
	};
}

#endif // GDOFSERIAL
