all:
	$(MAKE) -C $(dir $(CURDIR)/$(TARGET)) $(notdir $(TARGET))

clean:
	find . -name '*.o' -delete
	find . -type f -executable -delete