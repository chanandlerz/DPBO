public class Forum.Window : Gtk.ApplicationWindow {
    private Gtk.Box all_container;
    private Gtk.Box box;
    private Gtk.Box container_info_horizontal;
    private Gtk.Box container_info_vertical;
    private Gtk.Box other_info;
    private Gtk.Image post_image;
    private Gtk.Label post_caption;
    private Gtk.Box like_box;
    private Gtk.Button like_button;
    private Gtk.Label like_count;
    private Gtk.Entry comment_entry;
    private Gtk.Button comment_button;

    public Window (Gtk.Application app) {
        Object (
            application: app, default_height: 500, default_width: 500
        );
    }

    

    construct {
        this.title = "Forum";

        //  Gtk.Box vertical_box = new Gtk.Box (VERTICAL, 6);

        //  Gtk.Image profile_picture = new Gtk.Image.from_file ("/home/memories/Projects/dpbo-final-project/src/taku-morisaki.jpg");
        //  vertical_box.append (profile_picture);
        //  Gtk.Label username = new Gtk.Label ("memories");
        //  vertical_box.append (username);
        //  Gtk.Label posted_date = new Gtk.Label ("2 jam yang lalu");
        //  vertical_box.append (posted_date);

        all_container = new Gtk.Box (VERTICAL, 10);
        other_info = new Gtk.Box (HORIZONTAL, 5);
        box = new Gtk.Box (VERTICAL, 10);
        container_info_horizontal = new Gtk.Box (HORIZONTAL, 10);
        container_info_vertical = new Gtk.Box (VERTICAL, 5);

        Gtk.Image profile_picture = new Gtk.Image.from_file ("/home/memories/Projects/dpbo-final-project/src/taku-morisaki.jpg");
        profile_picture.set_pixel_size (30);
        container_info_horizontal.append (profile_picture);
        Gtk.Label username = new Gtk.Label ("memories");
        container_info_vertical.append (username);
        Gtk.Label posted_date = new Gtk.Label ("2 jam yang lalu");
        container_info_vertical.append (posted_date);
        container_info_horizontal.append (container_info_vertical);
        //  box.append (container_info_horizontal);
        post_image = new Gtk.Image.from_file ("/home/memories/Projects/dpbo-final-project/src/ghibli.jpg");
        post_image.set_pixel_size (500);
        post_caption = new Gtk.Label ("enih caption");
        like_box = new Gtk.Box (HORIZONTAL, 5);
        like_button = new Gtk.Button.from_icon_name ("emblem-favorite");
        like_count = new Gtk.Label ("0");
        comment_entry = new Gtk.Entry ();
        comment_button = new Gtk.Button.with_label ("Comment");

        box.append (post_image);
        box.append (post_caption);
        box.append (like_box);
        //  box.append (comment_entry);
        //  box.append (comment_button);

        like_box.append (like_button);
        like_box.append (like_count);

        other_info.append (box);

        all_container.append (container_info_horizontal);
        all_container.append (other_info);

        
        


        like_button.clicked.connect (() => {
            int count = int.parse (like_count.label);
            count++;
            like_count.label = count.to_string ();
        });


        comment_button.clicked.connect (() => {
            print ("Comment: %s\n", comment_entry.text);
            comment_entry.text = "";

        });


        this.set_child (all_container);
    }
}