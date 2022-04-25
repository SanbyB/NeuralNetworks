#pragma once


class OpenData{
public:
	OpenData();
	~OpenData();

	static unsigned char** read_mnist_images(std::string full_path, int& number_of_images, int& image_size);
};



