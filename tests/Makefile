
TESTS = bgmap16 \
		bgmap256 \
		bgscroll \
		debug \
		dsound \
		hud \
		irq \
		keys \
		math \
		mode3 \
		mode4 \
		mode5 \
		obj \
		profile \
		set_map_tile \
		sound1 \
		sound2 \
		sound3 \
		sound4 \
		sram

FINAL = $(join $(addsuffix /, $(TESTS)), $(addsuffix .gba, $(TESTS)))


all : $(FINAL)

%.gba :
	$(MAKE) -C$(@D)/src
#	$(MAKE) -C$(subst /output,, $(@D))/src

run :
	for file in $(FINAL); do \
		VisualBoyAdvance $$file; \
	done

clean :
	for dir in $(addsuffix /src,$(TESTS)); do \
		$(MAKE) -C$$dir clean; \
	done

