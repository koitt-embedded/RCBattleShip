#
#  ======== readme.txt ========
#

MessageQ Example

Program Logic:
The slave creates a message to pass data around. The host sends a message to
the slave core with a dummy payload. The slave then sends the message back to
the host. This process is repeated 14 times. Then the host a shutdown message
to the slave. The slave returns the message, shuts itself down and
reinitializes itself for future runs.
