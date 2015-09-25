/*
 *  代码功能：合肥公安采集程序配置文件的读取与写入
 *  接口介绍：initConfigInfo：初始化配置变量
	          readconfiginfo：读配置文件
			  writeconfiginfo：写配置文件
 *	代码作者：Ethan
 *	编辑时间：2015-09-25
 *	修改时间：v1.0(2015-09-25)
              完成主要功能的实现
 */
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "header.h"

#include <iostream>
#include <string>

struct Config{
	int up_hour, up_minute, up_second;
	int delete_hour, delete_minute, delete_second;
	int FD_iterations;
	int show_width, show_height;
	int pic_width, pic_height;
	double window_scale;
	int filesum;

	bool begin_flag;  /** <true表示开始采集图像，false表示不采集，这是由读卡器传输过来的信息*/
	int begin_photo_count;/** <存放当前目录下身份证文件的数目*/

	std::string card_photo_path;
	std::string copy_path;
	std::string save_path;

	int year, month, day, hour, minute, second;
};

class _Config : public Config{
public:
	void initConfigInfo(std::string = "config.xml");

	void readconfiginfo(std::string name,std::string& info);
	void readconfiginfo(std::string name,int& info);
	void readconfiginfo(std::string name,double& info );

	void writeconfiginfo();
	

private:
	std::string path;
};

#endif