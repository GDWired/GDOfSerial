#include "GDOfSerial.h"

#include <Godot.hpp>

using namespace godot;

GDOfSerial::GDOfSerial() : 
	m_serial()  {
}

GDOfSerial::~GDOfSerial() {
	end();
}

//###############################################################
//	Godot methods
//###############################################################

void GDOfSerial::_register_methods() {
	register_method("get_device_list", &GDOfSerial::get_device_list);
	register_method("begin", &GDOfSerial::begin);
	register_method("begin_with_config", &GDOfSerial::begin_with_config);
	register_method("is_initialized", &GDOfSerial::is_initialized);
	register_method("end", &GDOfSerial::end);
	register_method("available", &GDOfSerial::available);
	register_method("read", &GDOfSerial::read);
	register_method("read_string", &GDOfSerial::read_string);
	register_method("read_bytes", &GDOfSerial::read_bytes);
	register_method("print", &GDOfSerial::print);
	register_method("println", &GDOfSerial::println);
	register_method("write", &GDOfSerial::write);
	register_method("flush_in", &GDOfSerial::flush_in);
	register_method("flush_out", &GDOfSerial::flush_out);
	register_method("flush", &GDOfSerial::flush);
}

void GDOfSerial::_init() {
}

//###############################################################
//	Wrapped methods
//###############################################################

Array GDOfSerial::get_device_list() {
	const auto& l_devices = m_serial.getDeviceList();
	Array l_array;
	for (auto l_device : l_devices) {
		l_array.append(String(l_device.getDevicePath().c_str()));
	}
	return l_array;
}

bool GDOfSerial::begin(const String p_port_name, const int p_baudrate) {
	return m_serial.setup(std::string(p_port_name.utf8().get_data()), p_baudrate);
}

bool GDOfSerial::begin_with_config(const String p_port_name, const int p_baudrate, const int p_config) {
	int l_data = 8;
	int l_parity = OF_SERIAL_PARITY_N;
	int l_stop = 1;

	switch (p_config) {
		case SERIAL_5N1:
			l_data = 5;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 1;
			break;

		case SERIAL_6N1:
			l_data = 6;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 1;
			break;

		case SERIAL_7N1:
			l_data = 7;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 1;
			break;
			
		case SERIAL_5N2:
			l_data = 5;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 2;
			break;

		case SERIAL_6N2:
			l_data = 6;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 2;
			break;

		case SERIAL_7N2:
			l_data = 7;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 2;
			break;
		
		case SERIAL_8N2:
			l_data = 8;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 2;
			break;
		
		case SERIAL_5E1:
			l_data = 5;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 1;
			break;
		
		case SERIAL_6E1:
			l_data = 6;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 1;
			break;
		
		case SERIAL_7E1:
			l_data = 7;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 1;
			break;
					
		case SERIAL_8E1:
			l_data = 8;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 1;
			break;

		case SERIAL_5E2:
			l_data = 5;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 2;
			break;
					
		case SERIAL_6E2:
			l_data = 6;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 2;
			break;
					
		case SERIAL_7E2:
			l_data = 7;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 2;
			break;
					
		case SERIAL_8E2:
			l_data = 8;
			l_parity = OF_SERIAL_PARITY_E;
			l_stop = 2;
			break;

		case SERIAL_5O1:
			l_data = 5;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 1;
			break;
		
		case SERIAL_6O1:
			l_data = 6;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 1;
			break;
		
		case SERIAL_7O1:
			l_data = 7;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 1;
			break;
		
		case SERIAL_8O1:
			l_data = 8;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 1;
			break;
		
		case SERIAL_5O2:
			l_data = 5;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 2;
			break;
		
		case SERIAL_6O2:
			l_data = 6;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 2;
			break;
		
		case SERIAL_7O2:
			l_data = 7;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 2;
			break;
		
		case SERIAL_8O2:
			l_data = 8;
			l_parity = OF_SERIAL_PARITY_O;
			l_stop = 2;
			break;
		
		case SERIAL_8N1:	// the default
		default:
			l_data = 8;
			l_parity = OF_SERIAL_PARITY_N;
			l_stop = 1;
			break;
	}

	return m_serial.setup(std::string(p_port_name.utf8().get_data()), p_baudrate, l_data, l_parity, l_stop);
}

bool GDOfSerial::is_initialized() const {
	return m_serial.isInitialized();
}

void GDOfSerial::end() {
	m_serial.close();
}

int GDOfSerial::available() {
	return m_serial.available();
}

int GDOfSerial::read() {
	return m_serial.readData();
}

String GDOfSerial::read_string(const int p_lenght) {
	PoolByteArray l_raw_data = read_bytes(p_lenght);
	String l_buffer;
	for (int l_index = 0; l_index < l_raw_data.size(); ++l_index) {
		l_buffer += l_raw_data[l_index];
	}
	return l_buffer;
}

PoolByteArray GDOfSerial::read_bytes(const int p_lenght) {
	PoolByteArray l_byte_array;

	const int l_lenght = std::min(p_lenght, m_serial.available());
	if (l_lenght <= 0) {
		return l_byte_array;
	}

	std::vector<uint8_t> l_buffer; 
	l_buffer.reserve(l_lenght);
	
	uint8_t* l_bytes = l_buffer.data();
	m_serial.readData(l_bytes, l_lenght);

	l_byte_array.resize(l_lenght);
	for (int l_index = 0; l_index < l_buffer.size(); l_index++) {
		l_byte_array.append(l_bytes[l_index]);
	}

	return l_byte_array;
}

int GDOfSerial::print(const String p_buffer) {
	return m_serial.writeData(p_buffer.ascii().get_data(), p_buffer.length());
}

int GDOfSerial::println(const String p_buffer) {
	String l_buffer = p_buffer + "\n";
	return m_serial.writeData(l_buffer.ascii().get_data(), l_buffer.length());
}

int GDOfSerial::write(PoolByteArray p_buffer) {
	String l_buffer;
	for (int l_index = 0; l_index < p_buffer.size(); ++l_index) {
		l_buffer += p_buffer[l_index];
	}
	return m_serial.writeData(l_buffer.ascii().get_data(), l_buffer.length());
}

void GDOfSerial::flush_in() {
	m_serial.flush(true, false);
}

void GDOfSerial::flush_out() {
	m_serial.flush(false, true);
}

void GDOfSerial::flush() {
	m_serial.flush(true, true);
}

//###############################################################
//	Internals
//###############################################################

//###############################################################
//	Callback
//###############################################################

//###############################################################
//	Signals
//###############################################################
