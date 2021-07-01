function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 16};
	 this.metricsArray.var["rtInf"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 4};
	 this.metricsArray.var["rtMinusInf"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 4};
	 this.metricsArray.var["rtU"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 8};
	 this.metricsArray.var["rtY"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	size: 8};
	 this.metricsArray.fcn["Water_initialize"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 0,
	stackTotal: 24};
	 this.metricsArray.fcn["Water_step"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["rtGetInf"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtIsInf"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 13,
	stackTotal: 17};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "C:\\Windows\\System32\\Water_ert_rtw\\Water.c",
	stack: 0,
	stackTotal: 24};
	 this.metricsArray.fcn["sqrt"] = {file: "C:\\Program Files\\Polyspace\\R2019a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="Water_metrics.html">Global Memory: 68(bytes) Maximum Stack: 20(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
