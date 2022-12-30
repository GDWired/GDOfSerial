extends Node


onready var _serial: OfSerial = $OfSerial
onready var _data_line: LineEdit = $DataContainer/DataLine
onready var _terminal: TextEdit = $Terminal
onready var _hexa: CheckButton = $DataContainer/Hexa


func _ready() -> void:
	#print(_serial.begin("cu.usbserial-0001", 115200))
	var list: Array = _serial.get_device_list()
	_serial.begin(list[0], 115200)
	_serial.flush()
	# I, N, I, T
	_serial.write([0x49, 0x4E, 0x49, 0x54])


func _process(_delta):
	if _serial.available() > 0:
		#var data = _serial.read() # just one char
		if _hexa.pressed:
			var data_bytes: PoolByteArray = _serial.read_bytes(_serial.available())
			_terminal.text += "Data received ["
			for byte in data_bytes:
				_terminal.text += "0x%X" % byte + " " 
			_terminal.text += "]\n"
		else:
			var data_string: String = _serial.read_string(_serial.available())
			_terminal.text += "Data received [" + data_string + "]\n"


func _on_SendData_pressed():
	_serial.print(_data_line.text)
	_terminal.text += "Data sent [" + _data_line.text + "]\n"

