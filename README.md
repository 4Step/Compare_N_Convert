git issue: large files cannot be stored here and so the following three dlls are zipped (QT_dlls.zip)
  - Qt5Cored.dll
  - Qt5Guid.dll
  - Qt5Widgetsd.dll

# About:
    New Convert and Compare Program
    Redefines old compare transit program
    Software(By: Amar Sarvepalli - under works 2013,in C++11)

## Application Review:   
    - Software(written in 2007, in C++98)
    - Uses predefied fixed formats (such as text and DBF files)
    - Uses predefined data types and user should provide the input files in only this format (field width and type)
    - Checks only predefined attibutes (hardcoded in the source code)
    - Cannot change the field names
    - TCAD: User need to export both ROUTE and STOP files to DBF and then process the fields to predefined field types
    - CUBE: Process whitespaces between the keywords, wrapped lines as different between the itineraries     
    - TRANPLAN: same limitations as in CUBE
    - Limited to route files only.
    - Expects predefiend attributes in predefined data types and names
    - Works only for the predefined attributes.
    - Limitted to only two files (base<file1> and compare<file2>)

## Source Code:
    - Missing complete source code (missing main class or readDBF format class)
    - No common strucutre  : Each process (TRANPLAN, CUBE, TCAD and EMME) is a complete new class.
    - No read formats class: Uses predefined DFB library to read TCAD DBF files and is not part of main
    - No extendable classes: Only one class -Route network, which is defined in four differnt ways (one for each formats,not mutable)
    - No datatable class   : No datatable class, data is read in only route class and process from there
    - No compare itinerary class : No such common class. Each format based route classes are compared in their repective main().
    - No string processing : No string split class, trim class or remove whitespace class

## Need for Upgrade:
    - Well, need to include newer formats such as (GTFS, which is in *.CSV file)
    - Our work beyond NewStarts applications, where we need a simple file comparison method
      (without exporting to Excel readable formats and writing some compare formulas across fields)
    - Comparison during the development phase: Whether it is the model estimation, or calibration or other taks,
      there is no easy way to compare a few fields between files to get a sense of what's different
    - Scenario management: Need an easy tool to compare model inputs between two scenarios or same file across mutiple scenarios

## Software Setup: download and setup a new C++14 cross-compiler

## Requirements:
    GUI: Must have a Graphic User Interface
    Native formats: User should be ableto specify existing formats such as *.rts, *.bin for tcad
    GTFS: need to include to GTFS (*.csv or *.txt based formats)
    More than Transit Files: Feature to compare other table types: model-parameter, se-data and highway attributes
    Multiple file specification: User should be able to specify more than two files (base<file1> and compare<file2>)
    Two-way compare: User should be able to do
        1) SAME type of file across muliple scenarios (<file1>, <file2>, <file3>, ...<fileN>)
        2) DIFFERENT set of files across two scenarios(ex: Scenario-A {<file1>, <file2>,....<fileN>}, Scenario-B {<file1>, <file2>,....<fileN>})
           Here,<file1> from Scenario-A is compared to <file1> from Scenario-B
    Cross Platfroms: Not that we need but by default, should work on WindowsXP, Windows7, Windows8, Mac and Fedora (open OS).

## GUI Design: design broken down into five sections
    PART-0: Process
            Process_Type(radio buttons: 1.Compare Files, 2.Export tcad and other (*.bin), cube(*.dbf), cube(any except dbf), files to CSV)
    PART-A: FileTypeandFormat
            File_Type (General: Model tables, SEDATA tables and other simple txt or CSV or BIN files)
                      (Transit: compares route and stop attributes)     
                      (Highway: compares network attributes)                         
            File_Formats (dropdown menu: DBF, CSV, TXT, TRANPLAN, TPPLUS, CUBE-TRNBUILD, CUBE-PT, TCAD, EMME2, EMME3 and GTFS)
    PART-B: ComparisonType
            Type_of_comparison(check box: 1) one file type across multiple scenarios, 2) several file types between two scenarios)
            Number_of_Files(dropdown menu: {1 - 10})
            More_than_10_Files(check box: this allows user to specify custom compare.CTL files, and disables SAVE)
    PART-C: FileSpecifications
            inFile_specification: Label<file1>   Box<displayBrowsedFileName>  Button<browse>
                Label: shows file number
                Box  : Displays file name after selecting or by default shows "specify file1"
                Button: Opens windows file browser to look for Extension based on PART-A choices
                Extension chooser:
                PART-A:  File_Type              File_Formats    Extension
                         General or Highway      BIN             *.bin
                         General or Highway      CSV             *.csv
                         General or Highway      TXT             *.txt                         
                         General or Highway      DBF             *.dbf                     
                         Transit                 CSV             *.csv  
                         Transit                 TXT             *.txt                         
                         Transit                 DBF             *.DBF  
                         Transit                 TCAD            *.rts
                         Transit                 CUBE-PT         *.lin
                         Transit                 CUBE-TRNBUILD   *.* (all since no specific extentsion)
                         Transit                 TPPLUS          *.* (all since no specific extentsion)
                         Transit                 TRANPLAN        *.* (all since no specific extentsion)
                         Transit                 EMME2           *.* (Not sure)
                         Transit                 EMME3           *.* (Not sure)
                         Transit                 GTFS            *.txt
            outFile_specification: Label<fileName>   Box<displayBrowsedFileName>  Button<browse> CheckBox<outputMultipleFiles>
                CheckBox: This option exists only for PART-B > OPTION-2, where the we want to see separateoutput for different filetypes.
            This split into two sections (SET-A: left side and SET-B: rightside)
            Each section has upto 10 file specifications
            PART-B > OPTION-1: Always enables SET-A (left side) but limits the number of inFile_specification to Number_of_Files
            PART-B > OPTION-2: Enables only SET-B (left side) but limits inFile_specification by Number_of_Files
    PART-D: GUI Settings
            SAVE settings (button to save current choices to Compare.CTL)
            LOAD settings (button to load previously saved Compare.CTL)
            RSET settings (button to clear out all current settings, back to default)
            COMPARE (button to run the compare data)
            CLOSE settings(button to close and exit the program, this also kills the program if something goes wrong)

## Outputs
The number of outputs files directly correspond to Number_of_Files. However, the contents vary by PART-B > OPTIONS
  - PART-B > OPTION-1: This is a many-to-many comparison. For example, if user specifies 10 files, then it compares 90 datatables
                     output <file1> contains comparison of <file1> with all remaining files (file2...file10)
                     output <file2> contains comparison of <file2> with all remaining files (file1,file3...file10)
  - PART-B > OPTION-2: This is a one-to-one comparison. For example, if user specifies 10 files in SET-A and 10 files in SET-B,
                     output <file1> contains comparison of SET-A<file1> to SET-B<file1>, only one table comparison
                     output <file2> contains comparison of SET-A<file1> to SET-B<file1>, only one table comparison


## Design Approach and Classes
Converter: Converts different formats into CSV fileformat.
Tables to use field structure (vector<fieldType>fields and array fields)

     -  Level:0   CLASS: Converter (reads Compare.CTL and converts all specified files to *.csv files,
                          routes are split into _Routes.csv and _Stops.csv)
     -  Level:0   CLASS: Compare (reads Compare.CTL, CompareFieldInfo, creates either
                          1) builds TableData & CompareTableData & SummaryStats or
                          2) builds BuildRouteTable & CompareRouteItinerary)
     -  Level:1   CLASS: ReadCTLFile (reads the control file and gets the user settings)
     -  Level:1   CLASS: CompareFieldInfo
     -  Level:1   CLASS: ExportBINToCSV (simply exports binary file to csv formats)
     -  Level:1   CLASS: ExportDBFToCSV (simply exports DBF file to csv formats)
     -  Level:1   CLASS: ExportCUBEToCSV (simply exports cube trasnit line files to csv formats)
     -  Level:1   CLASS: OutputReport (writes output to the file,include methods, write.csv and write.txt)
     -  Level:1   CLASS: BuildTableData (array of fields with row elements, converts vector<dataType> array<dataType> and methods to get & set data to these fields)
     -  Level:1   CLASS: BuildRouteTable (builds route table with ID,Name,mode,Headway1,Headway2,Headway3,Fare<optional>,Stops,Nodes,Delay(same number as stops)
     -  Level:1   CLASS: CompareDataTables (creates a third table and reports differnces between the two tables)
     -  Level:2   CLASS: CompareRouteItinerary(specific to transit where node/stops info is appended to lines)
     -  Level:2   CLASS: CompareGeneralData (compares all common fields) between two or more files
     -  Level:2   CLASS: SummaryStats(computes, column sums, min and maximum value and count(not null), returns the position of row with pmin and pmax)
     -  Level:3   CLASS: ReadFormats (on transit side: identifies the file extension and looks for header files)
     -  Level:4   CLASS: ReadBINFile (reads binary files, relies on DCB file for header info and creates vector<dataType> for each field)
     -  Level:4   CLASS: Read_TCAD_Routes (reads transit lines and stops, tagged nodes)
     -  Level:4   CLASS: Read_TRNBUILD_Routes (reads transit lines and stops,nodes and stop delay, optional keywords)
     -  Level:4   CLASS: Read_PT_Routes (reads transit lines and stops,nodes and stop delay, optional keywords)
     -  Level:4   CLASS: Read_TPPLUS_Routes (reads transit lines and stops,nodes and stop delay, optional keywords)
     -  Level:4   CLASS: Read_TRANPLAN_Routes (reads transit lines and stops,nodes and stop delay)
     -  Level:4   CLASS: Read_EMME2_Routes (reads transit lines and stops,nodes and stop delay, optional keywords)
     -  Level:4   CLASS: Read_EMME3_Routes (reads transit lines and stops,nodes and stop delay, optional keywords)
     -  Level:4   CLASS: Read_GTFS_Routes  (reads transit lines and stops,nodes and stop delay)
     -  Level:5   CLASS: ReadDCBFile (filename extracted from main binary file and returns field names, field types and field bytes)
     -  Level:5   CLASS: ReadBINFile (filename extracted from main binary file and returns field names, field types and field bytes)
     -  Level:5   CLASS: ReadCSVFile
     -  Level:5   CLASS: ReadDBFFile
     -  Level:5   CLASS: ReadTXTFile (route files)
     -  Level:5   CLASS: ReadFFTFile (fixedformat text, uses 3 spaces to determine the field break point)
     -  Level:5   CLASS: WriteTableData (writes out table data from both routeTable(Route and Stop) and dataTable)

    ### Utility Classes:
     -  Level:6  CLASS: StringProcess (split, trim, remove whitespaces and replace space with underscore)
     -  Level:6  CLASS: ConvertVectorToArray (converts vector<dataType> Array<dataType>         -
     -  Create CLASS: StringProcess (split, trim, remove whitespace and replace space with underscore)
     -  Create CLASS: ConvertVectorToArray (converts vector<dataType> Array<dataType>
     -  Create CLASS: ReadDCBFile
     -  Create CLASS: ExportBINToCSV
     -  Create CLASS: ReadBINFile (info from ReadDCBFile, Reads Binary file contents)
