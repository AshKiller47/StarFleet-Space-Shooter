.PHONY: clean All

All:
	@echo "----------Building project:[ StarFleet - Release ]----------"
	@cd "StarFleet" && "$(MAKE)" -f  "StarFleet.mk"
clean:
	@echo "----------Cleaning project:[ StarFleet - Release ]----------"
	@cd "StarFleet" && "$(MAKE)" -f  "StarFleet.mk" clean
