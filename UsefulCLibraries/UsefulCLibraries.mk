##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UsefulCLibraries
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/mugiw/Documents/Workspaces/Workspace2
ProjectPath            :=C:/Users/mugiw/Documents/Workspaces/Workspace2/UsefulCLibraries
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/UsefulCLibraries
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
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/challenge.c$(ObjectSuffix) $(IntermediateDirectory)/assertLib.c$(ObjectSuffix) $(IntermediateDirectory)/generalLib.c$(ObjectSuffix) $(IntermediateDirectory)/datetimeLib.c$(ObjectSuffix) 



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
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/UsefulCLibraries/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/challenge.c$(ObjectSuffix): challenge.c $(IntermediateDirectory)/challenge.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/UsefulCLibraries/challenge.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/challenge.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/challenge.c$(DependSuffix): challenge.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/challenge.c$(ObjectSuffix) -MF$(IntermediateDirectory)/challenge.c$(DependSuffix) -MM challenge.c

$(IntermediateDirectory)/challenge.c$(PreprocessSuffix): challenge.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/challenge.c$(PreprocessSuffix) challenge.c

$(IntermediateDirectory)/assertLib.c$(ObjectSuffix): assertLib.c $(IntermediateDirectory)/assertLib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/UsefulCLibraries/assertLib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assertLib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assertLib.c$(DependSuffix): assertLib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assertLib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/assertLib.c$(DependSuffix) -MM assertLib.c

$(IntermediateDirectory)/assertLib.c$(PreprocessSuffix): assertLib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assertLib.c$(PreprocessSuffix) assertLib.c

$(IntermediateDirectory)/generalLib.c$(ObjectSuffix): generalLib.c $(IntermediateDirectory)/generalLib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/UsefulCLibraries/generalLib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/generalLib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/generalLib.c$(DependSuffix): generalLib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/generalLib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/generalLib.c$(DependSuffix) -MM generalLib.c

$(IntermediateDirectory)/generalLib.c$(PreprocessSuffix): generalLib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/generalLib.c$(PreprocessSuffix) generalLib.c

$(IntermediateDirectory)/datetimeLib.c$(ObjectSuffix): datetimeLib.c $(IntermediateDirectory)/datetimeLib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/mugiw/Documents/Workspaces/Workspace2/UsefulCLibraries/datetimeLib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/datetimeLib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/datetimeLib.c$(DependSuffix): datetimeLib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/datetimeLib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/datetimeLib.c$(DependSuffix) -MM datetimeLib.c

$(IntermediateDirectory)/datetimeLib.c$(PreprocessSuffix): datetimeLib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/datetimeLib.c$(PreprocessSuffix) datetimeLib.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


