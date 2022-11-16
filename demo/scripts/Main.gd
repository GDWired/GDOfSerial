extends Node

onready var _serial: OfSerial = $OfSerial

func _ready() -> void:
	#print(_serial.begin("cu.usbserial-0001", 115200))
	print(_serial.begin("cu.usbmodem1101", 115200))
	_serial.flush()
	_serial.write(['0x65', '0x66', '0x67', '0x68'])
	while _serial.available() <= 0: pass
	var data = String(_serial.read_string(_serial.available()))
	print(data)
	_serial.end()


func _process(_delta: float) -> void:
	pass
