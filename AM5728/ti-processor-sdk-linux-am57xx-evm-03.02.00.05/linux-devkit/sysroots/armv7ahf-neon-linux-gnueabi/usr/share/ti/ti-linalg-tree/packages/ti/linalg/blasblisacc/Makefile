include ../make.inc

# use all for cross compilation

# build library
all:
	cd src; $(MAKE)
	
crossC66x: 
	cd src; $(MAKE) crossC66x	
	
crossAM57x:
	cd src; $(MAKE) crossAM57x	
	
crossShannon:
	cd src; $(MAKE) crossShannon	
	
debug:
	cd src; $(MAKE) debug

# clean everything
clean::
	cd src; $(MAKE) clean

# clean only created objects
cleanObj:
	cd src; $(MAKE) cleanObj
