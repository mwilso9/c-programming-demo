##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=AdvancedFunctions
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/AdvancedFunctions
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/AdvancedFunctions
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mugiw
Date                   :=27/05/2024
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir -p
LinkerName             :=C:/cygwin64/bin/gcc.exe
SharedObjectLinkerName :=C:/cygwin64/bin/gcc.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/mugiw/Documents/Workspaces/Workspace2/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/cygwin64/bin/ar.exe rcu
CXX      := C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe
CC       := C:/cygwin64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -O0 -gdwarf-2 -std=c99 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/variadic.c$(ObjectSuffix) $(IntermediateDirectory)/recursion.c$(ObjectSuffix) $(IntermediateDirectory)/recursionChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/variadicChallenge.c$(ObjectSuffix) $(IntermediateDirectory)/inline_noreturn.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/AdvancedFunctions/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/variadic.c$(ObjectSuffix): variadic.c $(IntermediateDirectory)/variadic.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/AdvancedFunctions/variadic.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/variadic.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/variadic.c$(DependSuffix): variadic.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/variadic.c$(ObjectSuffix) -MF$(IntermediateDirectory)/variadic.c$(DependSuffix) -MM variadic.c

$(IntermediateDirectory)/variadic.c$(PreprocessSuffix): variadic.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/variadic.c$(PreprocessSuffix) variadic.c

$(IntermediateDirectory)/recursion.c$(ObjectSuffix): recursion.c $(IntermediateDirectory)/recursion.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/AdvancedFunctions/recursion.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/recursion.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/recursion.c$(DependSuffix): recursion.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/recursion.c$(ObjectSuffix) -MF$(IntermediateDirectory)/recursion.c$(DependSuffix) -MM recursion.c

$(IntermediateDirectory)/recursion.c$(PreprocessSuffix): recursion.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/recursion.c$(PreprocessSuffix) recursion.c

$(IntermediateDirectory)/recursionChallenge.c$(ObjectSuffix): recursionChallenge.c $(IntermediateDirectory)/recursionChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/AdvancedFunctions/recursionChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/recursionChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/recursionChallenge.c$(DependSuffix): recursionChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/recursionChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/recursionChallenge.c$(DependSuffix) -MM recursionChallenge.c

$(IntermediateDirectory)/recursionChallenge.c$(PreprocessSuffix): recursionChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/recursionChallenge.c$(PreprocessSuffix) recursionChallenge.c

$(IntermediateDirectory)/variadicChallenge.c$(ObjectSuffix): variadicChallenge.c $(IntermediateDirectory)/variadicChallenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/AdvancedFunctions/variadicChallenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/variadicChallenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/variadicChallenge.c$(DependSuffix): variadicChallenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/variadicChallenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/variadicChallenge.c$(DependSuffix) -MM variadicChallenge.c

$(IntermediateDirectory)/variadicChallenge.c$(PreprocessSuffix): variadicChallenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/variadicChallenge.c$(PreprocessSuffix) variadicChallenge.c

$(IntermediateDirectory)/inline_noreturn.c$(ObjectSuffix): inline_noreturn.c $(IntermediateDirectory)/inline_noreturn.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/AdvancedFunctions/inline_noreturn.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/inline_noreturn.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/inline_noreturn.c$(DependSuffix): inline_noreturn.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/inline_noreturn.c$(ObjectSuffix) -MF$(IntermediateDirectory)/inline_noreturn.c$(DependSuffix) -MM inline_noreturn.c

$(IntermediateDirectory)/inline_noreturn.c$(PreprocessSuffix): inline_noreturn.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/inline_noreturn.c$(PreprocessSuffix) inline_noreturn.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


