/*
 *  ���빦�ܣ��Ϸʹ����ɼ����������ļ��Ķ�ȡ��д��
 *  �ӿڽ��ܣ�initConfigInfo����ʼ�����ñ���
	          readconfiginfo���������ļ�
			  writeconfiginfo��д�����ļ�
 *	�������ߣ�Ethan
 *	�༭ʱ�䣺2015-09-25
 *	�޸�ʱ�䣺v1.0(2015-09-25)
              �����Ҫ���ܵ�ʵ��
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

	bool begin_flag;  /** <true��ʾ��ʼ�ɼ�ͼ��false��ʾ���ɼ��������ɶ����������������Ϣ*/
	int begin_photo_count;/** <��ŵ�ǰĿ¼�����֤�ļ�����Ŀ*/

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