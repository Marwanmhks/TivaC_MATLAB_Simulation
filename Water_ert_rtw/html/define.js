function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:35,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:71,type:"fcn"};
this.def["rtDW"] = {file: "Water_c.html",line:22,type:"var"};
this.def["rtU"] = {file: "Water_c.html",line:25,type:"var"};
this.def["rtY"] = {file: "Water_c.html",line:28,type:"var"};
this.def["BigEndianIEEEDouble"] = {file: "Water_c.html",line:49,type:"type"};
this.def["LittleEndianIEEEDouble"] = {file: "Water_c.html",line:56,type:"type"};
this.def["IEEESingle"] = {file: "Water_c.html",line:63,type:"type"};
this.def["rtInf"] = {file: "Water_c.html",line:65,type:"var"};
this.def["rtMinusInf"] = {file: "Water_c.html",line:66,type:"var"};
this.def["rtNaN"] = {file: "Water_c.html",line:67,type:"var"};
this.def["rtInfF"] = {file: "Water_c.html",line:68,type:"var"};
this.def["rtMinusInfF"] = {file: "Water_c.html",line:69,type:"var"};
this.def["rtNaNF"] = {file: "Water_c.html",line:70,type:"var"};
this.def["rtGetInf"] = {file: "Water_c.html",line:78,type:"fcn"};
this.def["rtGetInfF"] = {file: "Water_c.html",line:102,type:"fcn"};
this.def["rtGetMinusInf"] = {file: "Water_c.html",line:113,type:"fcn"};
this.def["rtGetMinusInfF"] = {file: "Water_c.html",line:137,type:"fcn"};
this.def["rt_InitInfAndNaN"] = {file: "Water_c.html",line:148,type:"fcn"};
this.def["rtIsInf"] = {file: "Water_c.html",line:160,type:"fcn"};
this.def["rtIsInfF"] = {file: "Water_c.html",line:166,type:"fcn"};
this.def["rtIsNaN"] = {file: "Water_c.html",line:172,type:"fcn"};
this.def["rtIsNaNF"] = {file: "Water_c.html",line:194,type:"fcn"};
this.def["rtGetNaN"] = {file: "Water_c.html",line:206,type:"fcn"};
this.def["rtGetNaNF"] = {file: "Water_c.html",line:230,type:"fcn"};
this.def["Water_step"] = {file: "Water_c.html",line:239,type:"fcn"};
this.def["Water_initialize"] = {file: "Water_c.html",line:283,type:"fcn"};
this.def["DW"] = {file: "Water_h.html",line:33,type:"type"};
this.def["ExtU"] = {file: "Water_h.html",line:38,type:"type"};
this.def["ExtY"] = {file: "Water_h.html",line:43,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["Water_c.html"] = "../Water.c";
	this.html2Root["Water_c.html"] = "Water_c.html";
	this.html2SrcPath["Water_h.html"] = "../Water.h";
	this.html2Root["Water_h.html"] = "Water_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","Water_c.html","Water_h.html","rtwtypes_h.html"];
