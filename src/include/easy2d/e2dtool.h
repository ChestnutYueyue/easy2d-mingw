#pragma once
#include <easy2d/e2dbase.h>

namespace easy2d
{


// 随机数产生器
class Random
{
public:
	// 取得范围内的一个整型随机数
	template<typename T>
	static inline T range(T min, T max) 
	{ 
		return easy2d::Random::__randomInt(min, max); 
	}

	// 取得范围内的一个浮点数随机数
	static inline float range(float min, float max) 
	{ 
		return easy2d::Random::__randomReal(min, max); 
	}

	// 取得范围内的一个浮点数随机数
	static inline double range(double min, double max)
	{ 
		return easy2d::Random::__randomReal(min, max); 
	}

private:
	template<typename T>
	static T __randomInt(T min, T max)
	{
		std::uniform_int_distribution<T> dist(min, max);
		return dist(Random::__getEngine());
	}

	template<typename T>
	static T __randomReal(T min, T max)
	{
		std::uniform_real_distribution<T> dist(min, max);
		return dist(Random::__getEngine());
	}

	// 获取随机数产生器
	static std::default_random_engine &__getEngine();
};


// 音乐
class Music :
	public Object
{
	friend class Game;

public:
	Music();

	explicit Music(
		const String& filePath		/* 音乐文件路径 */
	);

	Music(
		int resNameId,				/* 音乐资源名称 */
		const String& resType		/* 音乐资源类型 */
	);

	virtual ~Music();

	// 打开音乐文件
	bool open(
		const String& filePath		/* 音乐文件路径 */
	);

	// 打开音乐资源
	bool open(
		int resNameId,				/* 音乐资源名称 */
		const String& resType		/* 音乐资源类型 */
	);

	// 播放
	bool play(
		int nLoopCount = 0
	);

	// 暂停
	void pause();

	// 继续
	void resume();

	// 停止
	void stop();

	// 关闭并回收资源
	void close();

	// 是否正在播放
	bool isPlaying() const;

	// 设置音量
	bool setVolume(
		float volume
	);

private:
	static bool __init();

	static void __uninit();

private:
	class Media;
	Media* _media;
};


// 音乐播放器
class MusicPlayer
{
	friend class Game;

public:
	// 预加载音乐资源
	static Music* preload(
		const String& filePath	/* 音乐文件路径 */
	);

	// 播放音乐
	static bool play(
		const String& filePath,	/* 音乐文件路径 */
		int nLoopCount = 0		/* 重复播放次数，设置 -1 为循环播放 */
	);

	// 暂停音乐
	static void pause(
		const String& filePath	/* 音乐文件路径 */
	);

	// 继续播放音乐
	static void resume(
		const String& filePath	/* 音乐文件路径 */
	);

	// 停止音乐
	static void stop(
		const String& filePath	/* 音乐文件路径 */
	);

	// 获取音乐播放状态
	static bool isPlaying(
		const String& filePath	/* 音乐文件路径 */
	);

	// 预加载音乐资源
	static Music* preload(
		int resNameId,			/* 音乐资源名称 */
		const String& resType	/* 音乐资源类型 */
	);

	// 播放音乐
	static bool play(
		int resNameId,			/* 音乐资源名称 */
		const String& resType,	/* 音乐资源类型 */
		int nLoopCount = 0		/* 重复播放次数，设置 -1 为循环播放 */
	);

	// 暂停音乐
	static void pause(
		int resNameId,			/* 音乐资源名称 */
		const String& resType	/* 音乐资源类型 */
	);

	// 继续播放音乐
	static void resume(
		int resNameId,			/* 音乐资源名称 */
		const String& resType	/* 音乐资源类型 */
	);

	// 停止音乐
	static void stop(
		int resNameId,			/* 音乐资源名称 */
		const String& resType	/* 音乐资源类型 */
	);

	// 获取音乐播放状态
	static bool isPlaying(
		int resNameId,			/* 音乐资源名称 */
		const String& resType	/* 音乐资源类型 */
	);

	// 获取音量
	static float getVolume();

	// 设置音量
	static void setVolume(
		float volume			/* 音量范围为 -224 ~ 224，0 是静音，1 是正常音量 */
	);

	// 暂停所有音乐
	static void pauseAll();

	// 继续播放所有音乐
	static void resumeAll();

	// 停止所有音乐
	static void stopAll();

private:
	static void __uninit();
};


// 定时器
class Timer
{
	friend class Game;

public:
	// 添加定时器（每帧执行一次）
	static void add(
		const Function<void()>& func,	/* 执行函数 */
		const String& name = L""		/* 定时器名称 */
	);

	// 添加定时器
	static void add(
		const Function<void()>& func,	/* 执行函数 */
		float delay,					/* 时间间隔（秒） */
		int times = -1,					/* 执行次数（设 -1 为永久执行） */
		bool paused = false,			/* 是否暂停 */
		const String& name = L""		/* 定时器名称 */
	);

	// 在足够延迟后执行指定函数
	static void start(
		float timeout,					/* 等待的时长（秒） */
		const Function<void()>& func	/* 执行的函数 */
	);

	// 启动具有相同名称的定时器
	static void start(
		const String& name
	);

	// 停止具有相同名称的定时器
	static void stop(
		const String& name
	);

	// 移除具有相同名称的定时器
	static void remove(
		const String& name
	);

	// 启动所有定时器
	static void startAll();

	// 停止所有定时器
	static void stopAll();

	// 移除所有定时器
	static void removeAll();

private:
	// 更新定时器
	static void __update();

	// 重置定时器状态
	static void __resetAll();

	// 清空定时器
	static void __uninit();
};


// 数据管理工具
class Data
{
public:
	// 保存 int 类型的值
	static void saveInt(
		const String& key,					/* 键值 */
		int value,							/* 数据 */
		const String& field = L"Defalut"	/* 字段名称 */
	);

	// 保存 float 类型的值
	static void saveDouble(
		const String& key,					/* 键值 */
		float value,						/* 数据 */
		const String& field = L"Defalut"	/* 字段名称 */
	);

	// 保存 bool 类型的值
	static void saveBool(
		const String& key,					/* 键值 */
		bool value,							/* 数据 */
		const String& field = L"Defalut"	/* 字段名称 */
	);

	// 保存 字符串 类型的值
	static void saveString(
		const String& key,					/* 键值 */
		const String& value,				/* 数据 */
		const String& field = L"Defalut"	/* 字段名称 */
	);

	// 获取 int 类型的值
	// （若不存在则返回 defaultValue 参数的值）
	static int getInt(
		const String& key,					/* 键值 */
		int defaultValue,					/* 默认值 */
		const String& field = L"Defalut"	/* 字段名称 */
	);

	// 获取 float 类型的值
	// （若不存在则返回 defaultValue 参数的值）
	static float getDouble(
		const String& key,					/* 键值 */
		float defaultValue,				/* 默认值 */
		const String& field = L"Defalut"	/* 字段名称 */
	);

	// 获取 bool 类型的值
	// （若不存在则返回 defaultValue 参数的值）
	static bool getBool(
		const String& key,					/* 键值 */
		bool defaultValue,					/* 默认值 */
		const String& field = L"Defalut"	/* 字段名称 */
	);

	// 获取 字符串 类型的值
	// （若不存在则返回 defaultValue 参数的值）
	static String getString(
		const String& key,					/* 键值 */
		const String& defaultValue,			/* 默认值 */
		const String& field = L"Defalut"	/* 字段名称 */
	);
};


// 路径工具
class Path
{
	friend class Game;

public:
	// 添加搜索路径
	static void add(
		String path
	);

	// 检索文件路径
	static String searchForFile(
		const String& path
	);

	// 提取资源文件，返回提取后的文件路径
	static String extractResource(
		int resNameId,				/* 资源名称 */
		const String& resType,		/* 资源类型 */
		const String& destFileName	/* 目标文件名 */
	);

	// 获取数据的默认保存路径
	static String getDataSavePath();

	// 获取临时文件目录
	static String getTempPath();

	// 获取执行程序的绝对路径
	static String getExecutableFilePath();

	// 打开保存文件对话框
	static String getSaveFilePath(
		const String& title = L"保存到",		/* 对话框标题 */
		const String& defExt = L""			/* 默认扩展名 */
	);

	// 创建文件夹
	static bool createFolder(
		const String& dirPath	/* 文件夹路径 */
	);

	// 判断文件或文件夹是否存在
	static bool exists(
		const String& dirPath	/* 文件夹路径 */
	);

private:
	// 初始化
	static bool __init(
		const String& gameName
	);
};

}