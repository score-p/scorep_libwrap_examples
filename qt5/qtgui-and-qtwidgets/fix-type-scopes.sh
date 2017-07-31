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

prepend_type_scope AutoFormatting      QTextEdit
prepend_type_scope BlurHints           QGraphicsBlurEffect
prepend_type_scope CacheMode           QGraphicsView
prepend_type_scope ChangeFlags         QPinchGesture
prepend_type_scope DockWidgetFeatures  QDockWidget
prepend_type_scope EditTriggers        QAbstractItemView
prepend_type_scope FindFlags           QTextDocument
prepend_type_scope FontFilters         QFontComboBox
prepend_type_scope FormatOptions       QSurfaceFormat
prepend_type_scope GlyphRunFlags       QGlyphRun
prepend_type_scope GraphicsItemFlags   QGraphicsItem
prepend_type_scope Id                  QAccessible
prepend_type_scope InfoFlags           QTouchEvent::TouchPoint
prepend_type_scope InputDialogOptions  QInputDialog
prepend_type_scope InterfaceFactory    QAccessible
prepend_type_scope IteratorFlags       QTreeWidgetItemIterator
prepend_type_scope LayoutFlags         QRawFont
prepend_type_scope OptimizationFlags   QGraphicsView
prepend_type_scope Options             QFileIconProvider
prepend_type_scope PaintEngineFeatures QPaintEngine
prepend_type_scope PixmapFragmentHints QPainter
prepend_type_scope PixmapFragmentHints QPainter
prepend_type_scope RenderFlags         QTextItem
prepend_type_scope RenderHints         QPainter
prepend_type_scope RootObjectHandler   QAccessible
prepend_type_scope SceneLayers         QGraphicsScene
prepend_type_scope ShaderType          QOpenGLShader
prepend_type_scope StandardButtons     QDialogButtonBox
prepend_type_scope UpdateHandler       QAccessible
