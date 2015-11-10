#pragma once
#ifndef _CONFIG_H_
#define _CONFIG_H_

/*
 *  代码功能：合肥公安采集程序配置文件的读取与写入
 *  接口介绍：initConfigInfo：初始化配置变量
	          readconfiginfo：读配置文件
			  writeconfiginfo：写配置文件
 *	代码作者：Ethan
 *	编辑时间：2015-09-25
 *	修改时间：v1.0(2015-09-25)
              完成主要功能的实现
			  v2.0更改了主体实现，使用opencv C++方法
 */

#include "header.h"

#include <iostream>
#include <string>


class Config{
public:
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

class _Config : public Config
{
public:
	void initConfigInfo(std::string = "config.xml");

	template<typename InfoType>
	inline void readconfiginfo(std::string name,InfoType& info){
		FileStorage fs_r = FileStorage(path , FileStorage::READ);
		fs_r[name] >> info;
		fs_r.release();
	}
	
	void writeconfiginfo();
		
private:
	std::string path;
};



#endif