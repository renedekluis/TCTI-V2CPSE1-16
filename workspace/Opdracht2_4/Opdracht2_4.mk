##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Opdracht2_4
ConfigurationName      :=Debug
WorkspacePath          :="D:/Documents-(D)/HBO-ICT/git/HBO-ICT/Jaar4/C++ Herkansing/TCTI-V2CPSE1-16/workspace"
ProjectPath            :="D:/Documents-(D)/HBO-ICT/git/HBO-ICT/Jaar4/C++ Herkansing/TCTI-V2CPSE1-16/workspace/Opdracht2_4"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Rene
Date                   :=13/09/2018
CodeLitePath           :="D:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Opdracht2_4.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  -lgdi32 -static-libgcc -static-libstdc++ 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../Catch/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/converter.cpp$(ObjectSuffix) $(IntermediateDirectory)/note_player.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Documents-(D)/HBO-ICT/git/HBO-ICT/Jaar4/C++ Herkansing/TCTI-V2CPSE1-16/workspace/Opdracht2_4/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/converter.cpp$(ObjectSuffix): converter.cpp $(IntermediateDirectory)/converter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Documents-(D)/HBO-ICT/git/HBO-ICT/Jaar4/C++ Herkansing/TCTI-V2CPSE1-16/workspace/Opdracht2_4/converter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/converter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/converter.cpp$(DependSuffix): converter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/converter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/converter.cpp$(DependSuffix) -MM converter.cpp

$(IntermediateDirectory)/converter.cpp$(PreprocessSuffix): converter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/converter.cpp$(PreprocessSuffix) converter.cpp

$(IntermediateDirectory)/note_player.cpp$(ObjectSuffix): note_player.cpp $(IntermediateDirectory)/note_player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Documents-(D)/HBO-ICT/git/HBO-ICT/Jaar4/C++ Herkansing/TCTI-V2CPSE1-16/workspace/Opdracht2_4/note_player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/note_player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/note_player.cpp$(DependSuffix): note_player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/note_player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/note_player.cpp$(DependSuffix) -MM note_player.cpp

$(IntermediateDirectory)/note_player.cpp$(PreprocessSuffix): note_player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/note_player.cpp$(PreprocessSuffix) note_player.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


