/* forum.c generated by valac 0.56.0, the Vala compiler
 * generated from forum.vala, do not modify */

#include <gtk/gtk.h>
#include <glib-object.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define FORUM_TYPE_WINDOW (forum_window_get_type ())
#define FORUM_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FORUM_TYPE_WINDOW, ForumWindow))
#define FORUM_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FORUM_TYPE_WINDOW, ForumWindowClass))
#define FORUM_IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FORUM_TYPE_WINDOW))
#define FORUM_IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FORUM_TYPE_WINDOW))
#define FORUM_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FORUM_TYPE_WINDOW, ForumWindowClass))

typedef struct _ForumWindow ForumWindow;
typedef struct _ForumWindowClass ForumWindowClass;
typedef struct _ForumWindowPrivate ForumWindowPrivate;
enum  {
	FORUM_WINDOW_0_PROPERTY,
	FORUM_WINDOW_NUM_PROPERTIES
};
static GParamSpec* forum_window_properties[FORUM_WINDOW_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ForumWindow {
	GtkApplicationWindow parent_instance;
	ForumWindowPrivate * priv;
};

struct _ForumWindowClass {
	GtkApplicationWindowClass parent_class;
};

struct _ForumWindowPrivate {
	GtkBox* all_container;
	GtkBox* box;
	GtkBox* container_info_horizontal;
	GtkBox* container_info_vertical;
	GtkBox* other_info;
	GtkImage* post_image;
	GtkLabel* post_caption;
	GtkBox* like_box;
	GtkButton* like_button;
	GtkLabel* like_count;
	GtkEntry* comment_entry;
	GtkButton* comment_button;
};

static gint ForumWindow_private_offset;
static gpointer forum_window_parent_class = NULL;

VALA_EXTERN GType forum_window_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (ForumWindow, g_object_unref)
VALA_EXTERN ForumWindow* forum_window_new (GtkApplication* app);
VALA_EXTERN ForumWindow* forum_window_construct (GType object_type,
                                     GtkApplication* app);
static GObject * forum_window_constructor (GType type,
                                    guint n_construct_properties,
                                    GObjectConstructParam * construct_properties);
static void _forum_window___lambda6_ (ForumWindow* self);
static void __forum_window___lambda6__gtk_button_clicked (GtkButton* _sender,
                                                   gpointer self);
static void _forum_window___lambda7_ (ForumWindow* self);
static void __forum_window___lambda7__gtk_button_clicked (GtkButton* _sender,
                                                   gpointer self);
static void forum_window_finalize (GObject * obj);
static GType forum_window_get_type_once (void);

static inline gpointer
forum_window_get_instance_private (ForumWindow* self)
{
	return G_STRUCT_MEMBER_P (self, ForumWindow_private_offset);
}

ForumWindow*
forum_window_construct (GType object_type,
                        GtkApplication* app)
{
	ForumWindow * self = NULL;
#line 15 "../src/forum.vala"
	g_return_val_if_fail (app != NULL, NULL);
#line 16 "../src/forum.vala"
	self = (ForumWindow*) g_object_new (object_type, "application", app, "default-height", 500, "default-width", 500, NULL);
#line 15 "../src/forum.vala"
	return self;
#line 100 "forum.c"
}

ForumWindow*
forum_window_new (GtkApplication* app)
{
#line 15 "../src/forum.vala"
	return forum_window_construct (FORUM_TYPE_WINDOW, app);
#line 108 "forum.c"
}

static void
_forum_window___lambda6_ (ForumWindow* self)
{
	gint count = 0;
	GtkLabel* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	GtkLabel* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
#line 78 "../src/forum.vala"
	_tmp0_ = self->priv->like_count;
#line 78 "../src/forum.vala"
	_tmp1_ = gtk_label_get_label (_tmp0_);
#line 78 "../src/forum.vala"
	_tmp2_ = _tmp1_;
#line 78 "../src/forum.vala"
	count = atoi (_tmp2_);
#line 79 "../src/forum.vala"
	_tmp3_ = count;
#line 79 "../src/forum.vala"
	count = _tmp3_ + 1;
#line 80 "../src/forum.vala"
	_tmp4_ = self->priv->like_count;
#line 80 "../src/forum.vala"
	_tmp5_ = g_strdup_printf ("%i", count);
#line 80 "../src/forum.vala"
	_tmp6_ = _tmp5_;
#line 80 "../src/forum.vala"
	gtk_label_set_label (_tmp4_, _tmp6_);
#line 80 "../src/forum.vala"
	_g_free0 (_tmp6_);
#line 144 "forum.c"
}

static void
__forum_window___lambda6__gtk_button_clicked (GtkButton* _sender,
                                              gpointer self)
{
#line 77 "../src/forum.vala"
	_forum_window___lambda6_ ((ForumWindow*) self);
#line 153 "forum.c"
}

static void
_forum_window___lambda7_ (ForumWindow* self)
{
	GtkEntry* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	GtkEntry* _tmp3_;
#line 85 "../src/forum.vala"
	_tmp0_ = self->priv->comment_entry;
#line 85 "../src/forum.vala"
	_tmp1_ = gtk_editable_get_text ((GtkEditable*) _tmp0_);
#line 85 "../src/forum.vala"
	_tmp2_ = _tmp1_;
#line 85 "../src/forum.vala"
	g_print ("Comment: %s\n", _tmp2_);
#line 86 "../src/forum.vala"
	_tmp3_ = self->priv->comment_entry;
#line 86 "../src/forum.vala"
	gtk_editable_set_text ((GtkEditable*) _tmp3_, "");
#line 175 "forum.c"
}

static void
__forum_window___lambda7__gtk_button_clicked (GtkButton* _sender,
                                              gpointer self)
{
#line 84 "../src/forum.vala"
	_forum_window___lambda7_ ((ForumWindow*) self);
#line 184 "forum.c"
}

static GObject *
forum_window_constructor (GType type,
                          guint n_construct_properties,
                          GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	ForumWindow * self;
	GtkBox* _tmp0_;
	GtkBox* _tmp1_;
	GtkBox* _tmp2_;
	GtkBox* _tmp3_;
	GtkBox* _tmp4_;
	GtkImage* profile_picture = NULL;
	GtkImage* _tmp5_;
	GtkImage* _tmp6_;
	GtkBox* _tmp7_;
	GtkImage* _tmp8_;
	GtkLabel* username = NULL;
	GtkLabel* _tmp9_;
	GtkBox* _tmp10_;
	GtkLabel* _tmp11_;
	GtkLabel* posted_date = NULL;
	GtkLabel* _tmp12_;
	GtkBox* _tmp13_;
	GtkLabel* _tmp14_;
	GtkBox* _tmp15_;
	GtkBox* _tmp16_;
	GtkImage* _tmp17_;
	GtkImage* _tmp18_;
	GtkLabel* _tmp19_;
	GtkBox* _tmp20_;
	GtkButton* _tmp21_;
	GtkLabel* _tmp22_;
	GtkEntry* _tmp23_;
	GtkButton* _tmp24_;
	GtkBox* _tmp25_;
	GtkImage* _tmp26_;
	GtkBox* _tmp27_;
	GtkLabel* _tmp28_;
	GtkBox* _tmp29_;
	GtkBox* _tmp30_;
	GtkBox* _tmp31_;
	GtkButton* _tmp32_;
	GtkBox* _tmp33_;
	GtkLabel* _tmp34_;
	GtkBox* _tmp35_;
	GtkBox* _tmp36_;
	GtkBox* _tmp37_;
	GtkBox* _tmp38_;
	GtkBox* _tmp39_;
	GtkBox* _tmp40_;
	GtkButton* _tmp41_;
	GtkButton* _tmp42_;
	GtkBox* _tmp43_;
#line 23 "../src/forum.vala"
	parent_class = G_OBJECT_CLASS (forum_window_parent_class);
#line 23 "../src/forum.vala"
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
#line 23 "../src/forum.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FORUM_TYPE_WINDOW, ForumWindow);
#line 24 "../src/forum.vala"
	gtk_window_set_title ((GtkWindow*) self, "Forum");
#line 35 "../src/forum.vala"
	_tmp0_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
#line 35 "../src/forum.vala"
	g_object_ref_sink (_tmp0_);
#line 35 "../src/forum.vala"
	_g_object_unref0 (self->priv->all_container);
#line 35 "../src/forum.vala"
	self->priv->all_container = _tmp0_;
#line 36 "../src/forum.vala"
	_tmp1_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);
#line 36 "../src/forum.vala"
	g_object_ref_sink (_tmp1_);
#line 36 "../src/forum.vala"
	_g_object_unref0 (self->priv->other_info);
#line 36 "../src/forum.vala"
	self->priv->other_info = _tmp1_;
#line 37 "../src/forum.vala"
	_tmp2_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
#line 37 "../src/forum.vala"
	g_object_ref_sink (_tmp2_);
#line 37 "../src/forum.vala"
	_g_object_unref0 (self->priv->box);
#line 37 "../src/forum.vala"
	self->priv->box = _tmp2_;
#line 38 "../src/forum.vala"
	_tmp3_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);
#line 38 "../src/forum.vala"
	g_object_ref_sink (_tmp3_);
#line 38 "../src/forum.vala"
	_g_object_unref0 (self->priv->container_info_horizontal);
#line 38 "../src/forum.vala"
	self->priv->container_info_horizontal = _tmp3_;
#line 39 "../src/forum.vala"
	_tmp4_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
#line 39 "../src/forum.vala"
	g_object_ref_sink (_tmp4_);
#line 39 "../src/forum.vala"
	_g_object_unref0 (self->priv->container_info_vertical);
#line 39 "../src/forum.vala"
	self->priv->container_info_vertical = _tmp4_;
#line 41 "../src/forum.vala"
	_tmp5_ = (GtkImage*) gtk_image_new_from_file ("/home/memories/Projects/dpbo-final-project/src/taku-morisaki.jpg");
#line 41 "../src/forum.vala"
	g_object_ref_sink (_tmp5_);
#line 41 "../src/forum.vala"
	profile_picture = _tmp5_;
#line 42 "../src/forum.vala"
	_tmp6_ = profile_picture;
#line 42 "../src/forum.vala"
	gtk_image_set_pixel_size (_tmp6_, 30);
#line 43 "../src/forum.vala"
	_tmp7_ = self->priv->container_info_horizontal;
#line 43 "../src/forum.vala"
	_tmp8_ = profile_picture;
#line 43 "../src/forum.vala"
	gtk_box_append (_tmp7_, (GtkWidget*) _tmp8_);
#line 44 "../src/forum.vala"
	_tmp9_ = (GtkLabel*) gtk_label_new ("memories");
#line 44 "../src/forum.vala"
	g_object_ref_sink (_tmp9_);
#line 44 "../src/forum.vala"
	username = _tmp9_;
#line 45 "../src/forum.vala"
	_tmp10_ = self->priv->container_info_vertical;
#line 45 "../src/forum.vala"
	_tmp11_ = username;
#line 45 "../src/forum.vala"
	gtk_box_append (_tmp10_, (GtkWidget*) _tmp11_);
#line 46 "../src/forum.vala"
	_tmp12_ = (GtkLabel*) gtk_label_new ("2 jam yang lalu");
#line 46 "../src/forum.vala"
	g_object_ref_sink (_tmp12_);
#line 46 "../src/forum.vala"
	posted_date = _tmp12_;
#line 47 "../src/forum.vala"
	_tmp13_ = self->priv->container_info_vertical;
#line 47 "../src/forum.vala"
	_tmp14_ = posted_date;
#line 47 "../src/forum.vala"
	gtk_box_append (_tmp13_, (GtkWidget*) _tmp14_);
#line 48 "../src/forum.vala"
	_tmp15_ = self->priv->container_info_horizontal;
#line 48 "../src/forum.vala"
	_tmp16_ = self->priv->container_info_vertical;
#line 48 "../src/forum.vala"
	gtk_box_append (_tmp15_, (GtkWidget*) _tmp16_);
#line 50 "../src/forum.vala"
	_tmp17_ = (GtkImage*) gtk_image_new_from_file ("/home/memories/Projects/dpbo-final-project/src/ghibli.jpg");
#line 50 "../src/forum.vala"
	g_object_ref_sink (_tmp17_);
#line 50 "../src/forum.vala"
	_g_object_unref0 (self->priv->post_image);
#line 50 "../src/forum.vala"
	self->priv->post_image = _tmp17_;
#line 51 "../src/forum.vala"
	_tmp18_ = self->priv->post_image;
#line 51 "../src/forum.vala"
	gtk_image_set_pixel_size (_tmp18_, 500);
#line 52 "../src/forum.vala"
	_tmp19_ = (GtkLabel*) gtk_label_new ("enih caption");
#line 52 "../src/forum.vala"
	g_object_ref_sink (_tmp19_);
#line 52 "../src/forum.vala"
	_g_object_unref0 (self->priv->post_caption);
#line 52 "../src/forum.vala"
	self->priv->post_caption = _tmp19_;
#line 53 "../src/forum.vala"
	_tmp20_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);
#line 53 "../src/forum.vala"
	g_object_ref_sink (_tmp20_);
#line 53 "../src/forum.vala"
	_g_object_unref0 (self->priv->like_box);
#line 53 "../src/forum.vala"
	self->priv->like_box = _tmp20_;
#line 54 "../src/forum.vala"
	_tmp21_ = (GtkButton*) gtk_button_new_from_icon_name ("emblem-favorite");
#line 54 "../src/forum.vala"
	g_object_ref_sink (_tmp21_);
#line 54 "../src/forum.vala"
	_g_object_unref0 (self->priv->like_button);
#line 54 "../src/forum.vala"
	self->priv->like_button = _tmp21_;
#line 55 "../src/forum.vala"
	_tmp22_ = (GtkLabel*) gtk_label_new ("0");
#line 55 "../src/forum.vala"
	g_object_ref_sink (_tmp22_);
#line 55 "../src/forum.vala"
	_g_object_unref0 (self->priv->like_count);
#line 55 "../src/forum.vala"
	self->priv->like_count = _tmp22_;
#line 56 "../src/forum.vala"
	_tmp23_ = (GtkEntry*) gtk_entry_new ();
#line 56 "../src/forum.vala"
	g_object_ref_sink (_tmp23_);
#line 56 "../src/forum.vala"
	_g_object_unref0 (self->priv->comment_entry);
#line 56 "../src/forum.vala"
	self->priv->comment_entry = _tmp23_;
#line 57 "../src/forum.vala"
	_tmp24_ = (GtkButton*) gtk_button_new_with_label ("Comment");
#line 57 "../src/forum.vala"
	g_object_ref_sink (_tmp24_);
#line 57 "../src/forum.vala"
	_g_object_unref0 (self->priv->comment_button);
#line 57 "../src/forum.vala"
	self->priv->comment_button = _tmp24_;
#line 59 "../src/forum.vala"
	_tmp25_ = self->priv->box;
#line 59 "../src/forum.vala"
	_tmp26_ = self->priv->post_image;
#line 59 "../src/forum.vala"
	gtk_box_append (_tmp25_, (GtkWidget*) _tmp26_);
#line 60 "../src/forum.vala"
	_tmp27_ = self->priv->box;
#line 60 "../src/forum.vala"
	_tmp28_ = self->priv->post_caption;
#line 60 "../src/forum.vala"
	gtk_box_append (_tmp27_, (GtkWidget*) _tmp28_);
#line 61 "../src/forum.vala"
	_tmp29_ = self->priv->box;
#line 61 "../src/forum.vala"
	_tmp30_ = self->priv->like_box;
#line 61 "../src/forum.vala"
	gtk_box_append (_tmp29_, (GtkWidget*) _tmp30_);
#line 65 "../src/forum.vala"
	_tmp31_ = self->priv->like_box;
#line 65 "../src/forum.vala"
	_tmp32_ = self->priv->like_button;
#line 65 "../src/forum.vala"
	gtk_box_append (_tmp31_, (GtkWidget*) _tmp32_);
#line 66 "../src/forum.vala"
	_tmp33_ = self->priv->like_box;
#line 66 "../src/forum.vala"
	_tmp34_ = self->priv->like_count;
#line 66 "../src/forum.vala"
	gtk_box_append (_tmp33_, (GtkWidget*) _tmp34_);
#line 68 "../src/forum.vala"
	_tmp35_ = self->priv->other_info;
#line 68 "../src/forum.vala"
	_tmp36_ = self->priv->box;
#line 68 "../src/forum.vala"
	gtk_box_append (_tmp35_, (GtkWidget*) _tmp36_);
#line 70 "../src/forum.vala"
	_tmp37_ = self->priv->all_container;
#line 70 "../src/forum.vala"
	_tmp38_ = self->priv->container_info_horizontal;
#line 70 "../src/forum.vala"
	gtk_box_append (_tmp37_, (GtkWidget*) _tmp38_);
#line 71 "../src/forum.vala"
	_tmp39_ = self->priv->all_container;
#line 71 "../src/forum.vala"
	_tmp40_ = self->priv->other_info;
#line 71 "../src/forum.vala"
	gtk_box_append (_tmp39_, (GtkWidget*) _tmp40_);
#line 77 "../src/forum.vala"
	_tmp41_ = self->priv->like_button;
#line 77 "../src/forum.vala"
	g_signal_connect_object (_tmp41_, "clicked", (GCallback) __forum_window___lambda6__gtk_button_clicked, self, 0);
#line 84 "../src/forum.vala"
	_tmp42_ = self->priv->comment_button;
#line 84 "../src/forum.vala"
	g_signal_connect_object (_tmp42_, "clicked", (GCallback) __forum_window___lambda7__gtk_button_clicked, self, 0);
#line 91 "../src/forum.vala"
	_tmp43_ = self->priv->all_container;
#line 91 "../src/forum.vala"
	gtk_window_set_child ((GtkWindow*) self, (GtkWidget*) _tmp43_);
#line 23 "../src/forum.vala"
	_g_object_unref0 (posted_date);
#line 23 "../src/forum.vala"
	_g_object_unref0 (username);
#line 23 "../src/forum.vala"
	_g_object_unref0 (profile_picture);
#line 23 "../src/forum.vala"
	return obj;
#line 464 "forum.c"
}

static void
forum_window_class_init (ForumWindowClass * klass,
                         gpointer klass_data)
{
#line 1 "../src/forum.vala"
	forum_window_parent_class = g_type_class_peek_parent (klass);
#line 1 "../src/forum.vala"
	g_type_class_adjust_private_offset (klass, &ForumWindow_private_offset);
#line 1 "../src/forum.vala"
	G_OBJECT_CLASS (klass)->constructor = forum_window_constructor;
#line 1 "../src/forum.vala"
	G_OBJECT_CLASS (klass)->finalize = forum_window_finalize;
#line 479 "forum.c"
}

static void
forum_window_instance_init (ForumWindow * self,
                            gpointer klass)
{
#line 1 "../src/forum.vala"
	self->priv = forum_window_get_instance_private (self);
#line 488 "forum.c"
}

static void
forum_window_finalize (GObject * obj)
{
	ForumWindow * self;
#line 1 "../src/forum.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FORUM_TYPE_WINDOW, ForumWindow);
#line 2 "../src/forum.vala"
	_g_object_unref0 (self->priv->all_container);
#line 3 "../src/forum.vala"
	_g_object_unref0 (self->priv->box);
#line 4 "../src/forum.vala"
	_g_object_unref0 (self->priv->container_info_horizontal);
#line 5 "../src/forum.vala"
	_g_object_unref0 (self->priv->container_info_vertical);
#line 6 "../src/forum.vala"
	_g_object_unref0 (self->priv->other_info);
#line 7 "../src/forum.vala"
	_g_object_unref0 (self->priv->post_image);
#line 8 "../src/forum.vala"
	_g_object_unref0 (self->priv->post_caption);
#line 9 "../src/forum.vala"
	_g_object_unref0 (self->priv->like_box);
#line 10 "../src/forum.vala"
	_g_object_unref0 (self->priv->like_button);
#line 11 "../src/forum.vala"
	_g_object_unref0 (self->priv->like_count);
#line 12 "../src/forum.vala"
	_g_object_unref0 (self->priv->comment_entry);
#line 13 "../src/forum.vala"
	_g_object_unref0 (self->priv->comment_button);
#line 1 "../src/forum.vala"
	G_OBJECT_CLASS (forum_window_parent_class)->finalize (obj);
#line 523 "forum.c"
}

static GType
forum_window_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ForumWindowClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) forum_window_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ForumWindow), 0, (GInstanceInitFunc) forum_window_instance_init, NULL };
	GType forum_window_type_id;
	forum_window_type_id = g_type_register_static (gtk_application_window_get_type (), "ForumWindow", &g_define_type_info, 0);
	ForumWindow_private_offset = g_type_add_instance_private (forum_window_type_id, sizeof (ForumWindowPrivate));
	return forum_window_type_id;
}

GType
forum_window_get_type (void)
{
	static volatile gsize forum_window_type_id__once = 0;
	if (g_once_init_enter (&forum_window_type_id__once)) {
		GType forum_window_type_id;
		forum_window_type_id = forum_window_get_type_once ();
		g_once_init_leave (&forum_window_type_id__once, forum_window_type_id);
	}
	return forum_window_type_id__once;
}
