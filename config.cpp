#include "config.h"

using namespace std;

//初始化程序配置参数
void _Config::initConfigInfo(string configfilePath){
	path = configfilePath;

	begin_photo_count = 0;
	year = month = day = hour = minute = second = 0;

	CvFileNode *node;
	CvFileStorage *fs = cvOpenFileStorage(path.c_str(),0,CV_STORAGE_READ);
	node = cvGetFileNodeByName(fs,0,"Config");

	card_photo_path = cvReadStringByName(fs,node,"cardphotopath");
	copy_path = cvReadStringByName(fs,node,"copypath");
	save_path = cvReadStringByName(fs,node,"savepath");

	up_hour = cvReadIntByName(fs,node,"up_hour");
	up_minute = cvReadIntByName(fs,node,"up_minute");
    up_second = cvReadIntByName(fs,node,"up_second");

	delete_hour = cvReadIntByName(fs,node,"delete_hour");
	delete_minute = cvReadIntByName(fs,node,"delete_minute");
	delete_second = cvReadIntByName(fs,node,"delete_second");

	FD_iterations = cvReadIntByName(fs,node,"FD_iterations");

	show_width = cvReadIntByName(fs,node,"show_width");
	show_height = cvReadIntByName(fs,node,"show_height");

	pic_width = cvReadIntByName(fs,node,"pic_width");
	pic_height = cvReadIntByName(fs,node,"pic_height");

	window_scale = cvReadRealByName(fs,node,"window_scale");

	filesum = cvReadIntByName(fs,node,"filesum");

	cvReleaseFileStorage(&fs);
}

void _Config::readconfiginfo(string name,string& info){
	
	CvFileNode *node;
	CvFileStorage *fs = cvOpenFileStorage(path.c_str(),0,CV_STORAGE_READ);
	node = cvGetFileNodeByName(fs,0,"Config");

	info = cvReadStringByName(fs,node,name.c_str());
}

void _Config::readconfiginfo(std::string name,int& info){

	CvFileNode *node;
	CvFileStorage *fs = cvOpenFileStorage(path.c_str(),0,CV_STORAGE_READ);
	node = cvGetFileNodeByName(fs,0,"Config");

	info = cvReadIntByName(fs,node,name.c_str());
}

void _Config::readconfiginfo(std::string name,double& info ){
	CvFileNode *node;
	CvFileStorage *fs = cvOpenFileStorage(path.c_str(),0,CV_STORAGE_READ);
	node = cvGetFileNodeByName(fs,0,"Config");

	info = cvReadRealByName(fs,node,name.c_str());
}


void _Config::writeconfiginfo(){
	
	CvFileStorage *fs = cvOpenFileStorage(path.c_str(),0,CV_STORAGE_WRITE);

	cvWriteComment(fs,"配置文件",1);
	cvStartWriteStruct(fs,"Config",CV_NODE_MAP);

	cvWriteString(fs,"cardphotopath",card_photo_path.c_str());
	cvWriteString(fs,"copypath",copy_path.c_str());
	cvWriteString(fs,"savepath",save_path.c_str());
	cvWriteInt(fs,"up_hour",up_hour);
	cvWriteInt(fs,"up_minute",up_minute);
	cvWriteInt(fs,"up_second",up_second);

	cvWriteInt(fs,"delete_hour",delete_hour);
	cvWriteInt(fs,"delete_minute",delete_minute);
	cvWriteInt(fs,"delete_second",delete_second);

	cvWriteInt(fs,"FD_iterations",FD_iterations);

	cvWriteInt(fs,"show_width",show_width);
	cvWriteInt(fs,"show_height",show_height);

	cvWriteInt(fs,"pic_width",pic_width);
	cvWriteInt(fs,"pic_height",pic_height);

	cvWriteReal(fs,"window_scale",window_scale);

	

	cvWriteInt(fs,"filesum",filesum);

	cvEndWriteStruct(fs);
	cvReleaseFileStorage(&fs);
}


