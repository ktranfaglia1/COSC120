##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PokerGameFCS
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=E:/Codelite/workspace/ComputerScience120
ProjectPath            :=E:/Codelite/workspace/ComputerScience120/PokerGameFCS
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/PokerGameFCS
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=kylet
Date                   :=08/12/2022
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
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
OutputDirectory        :=E:/Codelite/workspace/ComputerScience120/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
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
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Deck.cpp$(ObjectSuffix) $(IntermediateDirectory)/Card.cpp$(ObjectSuffix) $(IntermediateDirectory)/PokerHand.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/workspace/ComputerScience120/PokerGameFCS/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Deck.cpp$(ObjectSuffix): Deck.cpp $(IntermediateDirectory)/Deck.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/workspace/ComputerScience120/PokerGameFCS/Deck.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Deck.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Deck.cpp$(DependSuffix): Deck.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Deck.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Deck.cpp$(DependSuffix) -MM Deck.cpp

$(IntermediateDirectory)/Deck.cpp$(PreprocessSuffix): Deck.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Deck.cpp$(PreprocessSuffix) Deck.cpp

$(IntermediateDirectory)/Card.cpp$(ObjectSuffix): Card.cpp $(IntermediateDirectory)/Card.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/workspace/ComputerScience120/PokerGameFCS/Card.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Card.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Card.cpp$(DependSuffix): Card.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Card.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Card.cpp$(DependSuffix) -MM Card.cpp

$(IntermediateDirectory)/Card.cpp$(PreprocessSuffix): Card.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Card.cpp$(PreprocessSuffix) Card.cpp

$(IntermediateDirectory)/PokerHand.cpp$(ObjectSuffix): PokerHand.cpp $(IntermediateDirectory)/PokerHand.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/workspace/ComputerScience120/PokerGameFCS/PokerHand.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PokerHand.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PokerHand.cpp$(DependSuffix): PokerHand.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PokerHand.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PokerHand.cpp$(DependSuffix) -MM PokerHand.cpp

$(IntermediateDirectory)/PokerHand.cpp$(PreprocessSuffix): PokerHand.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PokerHand.cpp$(PreprocessSuffix) PokerHand.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


