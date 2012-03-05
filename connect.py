
from bluetooth import *

client_socket=BluetoothSocket(RFCOMM)
client_socket.connect(("00:19:5D:EE:23:9D", 1))
while True:
	string = raw_input('w,a,s,d -->')
	if string == 'stop':
		break
	else:
		client_socket.send(string[0])
	
print "Finished"
client_socket.close()
