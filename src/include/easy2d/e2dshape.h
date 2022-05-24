#pragma once
#include <easy2d/e2dnode.h>

namespace easy2d
{


// 形状
class Shape :
	public Node
{
public:
	// 形状样式
	enum class Style
	{
		Solid,		/* 填充 */
		Round,		/* 轮廓 */
		Fill,		/* 轮廓 + 填充 */
	};

public:
	Shape();

	virtual ~Shape();

	// 获取样式
	Style getStyle() const;

	// 获取填充颜色
	Color getFillColor() const;

	// 获取线条颜色
	Color getLineColor() const;

	// 获取线条宽度
	float getStrokeWidth() const;

	// 设置填充颜色
	void setFillColor(
		Color fillColor
	);

	// 设置线条颜色
	void setLineColor(
		Color lineColor
	);

	// 设置线条宽度
	void setStrokeWidth(
		float strokeWidth
	);

	// 设置样式
	void setStyle(Style style);

	// 设置线条相交样式
	void setLineJoin(
		LineJoin lineJoin
	);

	// 渲染形状
	virtual void onRender() override;

protected:
	// 渲染轮廓
	virtual void _renderLine() = 0;

	// 渲染填充色
	virtual void _renderFill() = 0;

protected:
	Style	_style;
	float	_strokeWidth;
	Color	_lineColor;
	Color	_fillColor;
	ID2D1StrokeStyle * _strokeStyle;
};


// 矩形
class RectShape :
	public Shape
{
public:
	RectShape();

	explicit RectShape(
		Size size		/* 宽度和高度 */
	);

	explicit RectShape(
		Point topLeft,	/* 左上角坐标 */
		Size size		/* 宽度和高度 */
	);

	virtual ~RectShape();

protected:
	// 渲染轮廓
	virtual void _renderLine() override;

	// 渲染填充色
	virtual void _renderFill() override;
};


// 圆角矩形
class RoundRectShape :
	public Shape
{
public:
	RoundRectShape();

	explicit RoundRectShape(
		Size size,		/* 宽度和高度 */
		float radiusX,	/* 圆角半径 */
		float radiusY	/* 圆角半径 */
	);

	explicit RoundRectShape(
		Point topLeft,	/* 左上角坐标 */
		Size size,		/* 宽度和高度 */
		float radiusX,	/* 圆角半径 */
		float radiusY	/* 圆角半径 */
	);

	virtual ~RoundRectShape();

	// 获取圆角半径
	float getRadiusX() const;

	// 获取圆角半径
	float getRadiusY() const;

	// 设置圆角半径
	virtual void setRadiusX(
		float radiusX
	);

	// 设置圆角半径
	virtual void setRadiusY(
		float radiusY
	);

protected:
	// 渲染轮廓
	virtual void _renderLine() override;

	// 渲染填充色
	virtual void _renderFill() override;

protected:
	float _radiusX;
	float _radiusY;
};


// 圆形
class CircleShape :
	public Shape
{
public:
	CircleShape();

	explicit CircleShape(
		float radius	/* 半径 */
	);

	explicit CircleShape(
		Point center,	/* 圆心坐标 */
		float radius	/* 半径 */
	);

	virtual ~CircleShape();

	// 获取半径
	float getRadius() const;

	// 设置半径
	virtual void setRadius(
		float radius
	);

protected:
	// 渲染轮廓
	virtual void _renderLine() override;

	// 渲染填充色
	virtual void _renderFill() override;

protected:
	float _radius;
};


// 椭圆形
class EllipseShape :
	public Shape
{
public:
	EllipseShape();

	explicit EllipseShape(
		float radiusX,	/* 横轴半径 */
		float radiusY	/* 纵轴半径 */
	);

	explicit EllipseShape(
		Point center,	/* 圆心坐标 */
		float radiusX,	/* 横轴半径 */
		float radiusY	/* 纵轴半径 */
	);

	virtual ~EllipseShape();

	// 获取横轴半径
	float getRadiusX() const;

	// 获取纵轴半径
	float getRadiusY() const;

	// 设置横轴半径
	virtual void setRadiusX(
		float radiusX
	);

	// 设置纵轴半径
	virtual void setRadiusY(
		float radiusY
	);

protected:
	// 渲染轮廓
	virtual void _renderLine() override;

	// 渲染填充色
	virtual void _renderFill() override;

protected:
	float _radiusX;
	float _radiusY;
};

}