tool
extends EditorPlugin


func _enter_tree():
	add_custom_type("OfSerial", "Node", preload("GDOfSerial.gdns"), preload("icon.png"))


func _exit_tree():
	remove_custom_type("OfSerial")
