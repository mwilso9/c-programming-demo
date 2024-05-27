.PHONY: clean All

All:
	@echo "----------Building project:[ UsefulCLibraries - Debug ]----------"
	@cd "UsefulCLibraries" && "$(MAKE)" -f  "UsefulCLibraries.mk"
clean:
	@echo "----------Cleaning project:[ UsefulCLibraries - Debug ]----------"
	@cd "UsefulCLibraries" && "$(MAKE)" -f  "UsefulCLibraries.mk" clean
