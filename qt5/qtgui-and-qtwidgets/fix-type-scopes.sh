wrapper_name=qtgui_and_qtwidgets

prepend_type_scope() {
	if [ $# != 2 ]; then
		echo "Error: Wrong number of parameters. Has to be 2: $*" >&2
		return
	fi

	sed -i "s/^$1$/$2::$1/g" scorep_libwrap_$wrapper_name.cc
	sed -i "s/ $1 / $2::$1 /g" scorep_libwrap_$wrapper_name.cc
	sed -i "s/ $1 / $2::$1 /g" scorep_libwrap_$wrapper_name.inc.c
}

prepend_type_scope InfoFlags           QTouchEvent::TouchPoint
prepend_type_scope InterfaceFactory    QAccessible
prepend_type_scope UpdateHandler       QAccessible
prepend_type_scope RootObjectHandler   QAccessible
prepend_type_scope Id                  QAccessible
prepend_type_scope FormatOptions       QSurfaceFormat
prepend_type_scope FindFlags           QTextDocument
prepend_type_scope RenderFlags         QTextItem
prepend_type_scope RenderHints         QPainter
prepend_type_scope PaintEngineFeatures QPaintEngine
prepend_type_scope PixmapFragmentHints QPainter
prepend_type_scope LayoutFlags         QRawFont
prepend_type_scope PixmapFragmentHints QPainter
prepend_type_scope GlyphRunFlags       QGlyphRun
prepend_type_scope ShaderType          QOpenGLShader
