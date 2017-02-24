#
#  ======== readme.txt ========
#
MessageQ Example with power management enabled

Program Logic:
This is a MessageQ example using the client/server pattern. It is a two
processor example - messages are only sent between the host processor (client)
and the selected slave core (server).

The slave creates a message to pass data around. The host sends a
message to the slave core with a dummy payload. The slave then sends the
message back to the host. This process is repeated 14 times. Then the host a
shutdown message to the slave. The slave returns the message, shuts itself
down and reinitializes itself for future runs.

Power management is enabled on all slave cores in their corresponding
BIOS configuration files.
