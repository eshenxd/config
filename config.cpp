#include "config.h"

using std::string;
using std::vector;
using namespace cv;

void _Config::initConfigInfo(string configfilePath)
{
	path = configfilePath;
	FileStorage fs_r = FileStorage(path ,FileStorage::READ);

	fs_r["cardphotopath"] >> card_photo_path;
	fs_r["copypath"] >> copy_path;
	fs_r["savepath"] >> save_path;

	fs_r["up_hour"] >> up_hour;
	fs_r["up_minute"] >> up_minute;

	fs_r["delete_hour"] >> delete_hour;
	fs_r["delete_minute"] >> delete_minute;

	fs_r["FD_iterations"] >> FD_iterations;

	fs_r["show_width"] >> show_width;
	fs_r["show_height"] >> show_height;

	fs_r["pic_width"] >> pic_width;
	fs_r["pic_height"] >> pic_height;

	fs_r["window_scale"] >> window_scale;
	fs_r["filesum"] >> filesum;

	fs_r.release();
}

void _Config::writeconfiginfo()
{
	FileStorage fs_w = FileStorage(path,FileStorage::WRITE);
	
	fs_w << "cardphotopath" << card_photo_path;
	fs_w <<"copypath" << copy_path;
	fs_w <<"savepath" << save_path;

	fs_w <<"up_hour" << up_hour;
	fs_w <<"up_minute" << up_minute;
	
	fs_w << "delete_hour" << delete_hour;
	fs_w << "delete_minute" << delete_minute;

	fs_w << "FD_iterations" << FD_iterations;

	fs_w << "show_width" << show_width;
	fs_w << "show_height" << show_height;

	fs_w << "pic_width" << pic_width;
	fs_w << "pic_height" << pic_height;

	fs_w << "window_scale" << window_scale;

	fs_w << "filesum" << filesum;

	fs_w.release();

}