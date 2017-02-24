#
#  ======== readme.txt ========
#
MessageQ forward message example.

Program Logic:
The host sends a message to each slave core with a dummy payload. Each
slave then forwards the message to the other slave. After a slave
receives a message from both the host and the other slave, it
allocates a new message that it sends back to the host. The slave
shuts itself down and reinitializes itself for future runs.
