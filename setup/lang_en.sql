# ========================================================
# English Translation phrases for phpVideoPro
# ========================================================

UPDATE languages SET charset='iso-8859-1' WHERE lang_id='en';
INSERT INTO lang (message_id,lang,content) VALUES ('not_yet_implemented','en','Sorry - not yet implemented.');
INSERT INTO lang VALUES('medium','en','Medium');
INSERT INTO lang VALUES('nr','en','Nr');
INSERT INTO lang VALUES('title','en','Title');
INSERT INTO lang VALUES('length','en','Length');
INSERT INTO lang VALUES('year','en','Year');
INSERT INTO lang VALUES('date_rec','en','Date Aquired');
INSERT INTO lang VALUES('category','en','Category');
INSERT INTO lang VALUES('medialist','en','Medialist');
INSERT INTO lang VALUES('enter_min_free','en','Enter minimum of free space on medium to display:');
INSERT INTO lang VALUES('display','en','Display');
INSERT INTO lang VALUES('free_space_on_media','en','Following media have at least %1 minutes of free space available:');
INSERT INTO lang VALUES('free','en','Free');
INSERT INTO lang VALUES('content','en','Content');
INSERT INTO lang VALUES('filter_setup','en','Filter Setup');
INSERT INTO lang VALUES('mediatype','en','MediaType');
INSERT INTO lang VALUES('screen','en','Screen Format');
INSERT INTO lang VALUES('picture','en','Color Format');
INSERT INTO lang VALUES('tone','en','Tone Format');
INSERT INTO lang VALUES('longplay','en','LongPlay');
INSERT INTO lang VALUES('fsk','en','PG');
INSERT INTO lang VALUES('actor','en','Actor');
INSERT INTO lang VALUES('actors','en','Actors');
INSERT INTO lang VALUES('director','en','Director');
INSERT INTO lang VALUES('directors','en','Directors');
INSERT INTO lang VALUES('composer','en','Composer');
INSERT INTO lang VALUES('music','en','Composer');
INSERT INTO lang VALUES('min','en','min');
INSERT INTO lang VALUES('max','en','max');
INSERT INTO lang VALUES('s/w','en','b/w');
INSERT INTO lang VALUES('farbe','en','Color');
INSERT INTO lang VALUES('3d','en','3D');
INSERT INTO lang VALUES('edit_entry','en','Edit entry %1');
INSERT INTO lang VALUES('view_entry','en','View entry %1');
INSERT INTO lang VALUES('add_entry','en','Add entry');
INSERT INTO lang VALUES('unknown','en','unknown');
INSERT INTO lang VALUES('country','en','Country');
INSERT INTO lang VALUES('medianr','en','MediaNr');
INSERT INTO lang VALUES('highest_db_entries','en','highest entries in db');
INSERT INTO lang VALUES('no','en','No');
INSERT INTO lang VALUES('yes','en','Yes');
INSERT INTO lang VALUES('medialength','en','MediaLength');
INSERT INTO lang VALUES('minute_abbrev','en','min');
INSERT INTO lang VALUES('source','en','Source');
INSERT INTO lang VALUES('staff','en','Staff');
INSERT INTO lang VALUES('name','en','Name');
INSERT INTO lang VALUES('first_name','en','First Name');
INSERT INTO lang VALUES('in_list','en','in List');
INSERT INTO lang VALUES('comments','en','Comments');
INSERT INTO lang VALUES('cancel','en','Cancel');
INSERT INTO lang VALUES('create','en','Create');
INSERT INTO lang VALUES('update','en','Update');
INSERT INTO lang VALUES('edit','en','Edit');
INSERT INTO lang VALUES('delete','en','Delete');
INSERT INTO lang VALUES('invalid_media_nr','en','The MediaNr you specified is either incomplete or invalid. You must specify a <b>number</b> in <b>both</b> MediaNr fields.');
INSERT INTO lang VALUES('warning','en','warning');
INSERT INTO lang VALUES('of_aquiration','en','of aquiration');
INSERT INTO lang VALUES('wrong_date','en','The date %1 you specified (%2) is invalid. When entering a date here, please enter the day into the first, the month into the second and the year into the third date field and only use digits. If you are not sure about the exact date, enter zeros into the fields in question: e.g. "00" "02" "2002" means "eventually in February 2002", or "00" "00" "0000" means "sometimes".');
INSERT INTO lang VALUES('incomplete_date','en','If you do not know the exact date, but - for example - only that you aquired it in the year 2000, substitute zeros for the unknown data - in our example the date should look like "00" "00" "2000".');
INSERT INTO lang VALUES('dupe_id_entered','en','There is already an entry in the database for the entered media ID. Please hit the "Back" button of your browser and correct your input. Hint: There is a Select-Box next to the input box you specified the media number in. This select box tells you the highest existing movie id. Normally it is a good choice for a new media to increase the first (four-digit) number by one, or for a new movie on the same media, increase the second (two-digit) number by one.');
INSERT INTO lang VALUES('create_success','en','Entry created successfully');
INSERT INTO lang VALUES('update_failed','en','Failed to update entry');
INSERT INTO lang VALUES('update_success','en','Entry updated successfully');
INSERT INTO lang VALUES('about','en','About');
INSERT INTO lang VALUES('history','en','History');
INSERT INTO lang VALUES('view','en','View');
INSERT INTO lang VALUES('deleting_entry','en','Deleting entry %1');
INSERT INTO lang VALUES('free_space_title','en','Free space on media');
INSERT INTO lang VALUES('filter','en','Filter');
INSERT INTO lang VALUES('set_filter','en','Set Filter');
INSERT INTO lang VALUES('unset_filter','en','UnSet Filter');
INSERT INTO lang VALUES('taperest_absolute','en','TapeRest (absolute)');
INSERT INTO lang VALUES('taperest_filtered','en','TapeRest (filtered)');
INSERT INTO lang VALUES('help','en','Help');
INSERT INTO lang VALUES('general','en','General');
INSERT INTO lang VALUES('sure_to_delete','en','Are you sure you want to delete all data for %1');
INSERT INTO lang VALUES('nobody_named','en','There\'s no other movie by a %1 named %2 %3 in this db, so I remove this entry from the %1\'s table.');
INSERT INTO lang VALUES('compose_person','en','composer');
INSERT INTO lang VALUES('director_person','en','director');
INSERT INTO lang VALUES('check_completed','en','Check completed');
INSERT INTO lang VALUES('delete_remaining','en','now deleting remaining data for this movie from db');
INSERT INTO lang VALUES('ok','en','OK');
INSERT INTO lang VALUES('not_ok','en','Failed');
INSERT INTO lang VALUES('recalc_free','en','Re-calculating remaining free space on this medium');
INSERT INTO lang VALUES('tapelist_update_failed','en','Failed updating tape list');
INSERT INTO lang VALUES('no_entry_in_tapelist','en','Failed - no entry found in tape list');
INSERT INTO lang VALUES('finnished','en','Finnished');
INSERT INTO lang VALUES('time_left','en','%1 minutes left');
INSERT INTO lang VALUES('configuration','en','Configuration');
INSERT INTO lang VALUES('index','en','Index');
INSERT INTO lang VALUES('intro','en','Intro');
INSERT INTO lang VALUES('menues','en','Menues');
INSERT INTO lang VALUES('back','en','Back');
INSERT INTO lang VALUES('close','en','Close');
INSERT INTO lang VALUES('help_about','en','Help about');
INSERT INTO lang VALUES('actors_list','en','List of Actors');
INSERT INTO lang VALUES('directors_list','en','List of Directors');
INSERT INTO lang VALUES('music_list','en','List of Composers');
INSERT INTO lang VALUES('no_entries_found','en','No entries found');
INSERT INTO lang VALUES('no_space_of','en','There was no medium with a minimum of %1 min of free space found in the database.');
INSERT INTO lang VALUES('howto','en','How to...');
INSERT INTO lang VALUES('howto_lang','en','How to create a new language file');
INSERT INTO lang VALUES('howto_help','en','How to create a help file');
INSERT INTO lang VALUES('howto_templates','en','How to create a new template set');
INSERT INTO lang VALUES('language_settings','en','Language Settings');
INSERT INTO lang VALUES('scan_new_lang_files','en','Scan for new language files?');
INSERT INTO lang VALUES('scan_new_lang_comment','en','(If you created your own language file and put it into the setup directory, this will tell phpVideoPro to look for it)');
INSERT INTO lang VALUES('select_add_lang','en','Select additional language to install');
INSERT INTO lang VALUES('select_add_lang_comment','en','(English is already installed and always will be - see next item. For other languages that are already installed, see next item, too.)');
INSERT INTO lang VALUES('no_add_lang','en','No additional language available.');
INSERT INTO lang VALUES('refresh_lang','en','Refresh language');
INSERT INTO lang VALUES('refresh_lang_comment','en','(re-insert phrases from language file into db)');
INSERT INTO lang VALUES('none','en','None');
INSERT INTO lang VALUES('select_primary_lang','en','Select primary language');
INSERT INTO lang VALUES('select_primary_lang_comment','en','(for missing phrases, there will always be a fall-back to English)');
INSERT INTO lang VALUES('colors','en','Colors');
INSERT INTO lang VALUES('page_bg','en','Page Background');
INSERT INTO lang VALUES('table_bg','en','Table Background');
INSERT INTO lang VALUES('th_bg','en','Table Headers Background');
INSERT INTO lang VALUES('feedback_ok','en','Feedback "OK"');
INSERT INTO lang VALUES('feedback_err','en','Feedback "Failure"');
INSERT INTO lang VALUES('template_set','en','Template Set');
INSERT INTO lang VALUES('start_pvp','en','Start phpVideoPro');
INSERT INTO lang VALUES('hit_back_to_correct','en','Hit the "Back" button to correct the error.');
INSERT INTO lang VALUES('goto_entry','en','Directly go to entry:');
INSERT INTO lang VALUES('start_page','en','Initial page');
INSERT INTO lang VALUES('invalid_fsk','en','The value entered for %1 is invalid. %1 means Parental Guide, i.e. the minimum age below that you should give nobody access to this movie.');
INSERT INTO lang VALUES('counter_start_stop','en','Counter Start/Stop');
INSERT INTO lang VALUES('other_pages','en','Other pages');
INSERT INTO lang VALUES('commercials','en','Commercials');
INSERT INTO lang VALUES('cut_off','en','cut off');
INSERT INTO lang VALUES('display_limit','en','Display Limit');
INSERT INTO lang VALUES('display_limit_comment','en','(how many lines to display per page for lists)');
INSERT INTO lang VALUES('print_label','en','Print Label:');
INSERT INTO lang VALUES('howto_label','en','How to create/configure label templates');
INSERT INTO lang VALUES('label','en','Label');
INSERT INTO lang VALUES('print','en','Print');
INSERT INTO lang VALUES('medialist_num','en','Medialist in numerical order');
INSERT INTO lang VALUES('medialist_alpha','en','Medialist in alphabetical order');
INSERT INTO lang VALUES('lines_per_page','en','Lines per page');
INSERT INTO lang VALUES('lines_per_page_comment','en','This is for the printing functions to determine how many lines of text fit on one sheet of paper.');
INSERT INTO lang VALUES('date_format','en','Date format');
INSERT INTO lang VALUES('date_format_comment','en','What format to use for date display. Available formats are: y-m-d, d.m.y and d/m/y');
INSERT INTO lang VALUES('listgen','en','List Generator');
INSERT INTO lang VALUES('list','en','List');
INSERT INTO lang VALUES('format','en','Format');
INSERT INTO lang VALUES('line_count','en','Lines');
INSERT INTO lang VALUES('catlist_alpha','en','Medialist in alphabetical order, sorted by category');
INSERT INTO lang VALUES('lists','en','Lists');
INSERT INTO lang VALUES('labels','en','Labels');
INSERT INTO lang VALUES('cat_adventure','en','Adventure');
INSERT INTO lang VALUES('cat_action','en','Action');
INSERT INTO lang VALUES('cat_agents','en','Agent');
INSERT INTO lang VALUES('cat_bible','en','Bible');
INSERT INTO lang VALUES('cat_biography','en','Biography');
INSERT INTO lang VALUES('cat_stage','en','Stage');
INSERT INTO lang VALUES('cat_documentary','en','Documentation');
INSERT INTO lang VALUES('cat_drama','en','Drama');
INSERT INTO lang VALUES('cat_fantasy','en','Fantasy');
INSERT INTO lang VALUES('cat_party','en','Party');
INSERT INTO lang VALUES('cat_scary','en','Scary Movies');
INSERT INTO lang VALUES('cat_history','en','History');
INSERT INTO lang VALUES('cat_horror','en','Horror');
INSERT INTO lang VALUES('cat_judaica','en','Judaica');
INSERT INTO lang VALUES('cat_camera','en','Camera');
INSERT INTO lang VALUES('cat_catastrophe','en','Catastrophe');
INSERT INTO lang VALUES('cat_children','en','Children');
INSERT INTO lang VALUES('cat_comedy','en','Comedy');
INSERT INTO lang VALUES('cat_concert','en','Concert');
INSERT INTO lang VALUES('cat_war','en','War Movies');
INSERT INTO lang VALUES('cat_crime','en','Crime');
INSERT INTO lang VALUES('cat_love','en','Lovestories');
INSERT INTO lang VALUES('cat_fairytale','en','Fairytales');
INSERT INTO lang VALUES('cat_melodrama','en','Melodrama');
INSERT INTO lang VALUES('cat_monumental','en','Monumental');
INSERT INTO lang VALUES('cat_musical','en','Musical');
INSERT INTO lang VALUES('cat_music','en','Music');
INSERT INTO lang VALUES('cat_videoclip','en','Videoclip');
INSERT INTO lang VALUES('cat_musicmovie','en','Music Movies');
INSERT INTO lang VALUES('cat_nature','en','Nature');
INSERT INTO lang VALUES('cat_opera','en','Opera');
INSERT INTO lang VALUES('cat_operetta','en','Operetta');
INSERT INTO lang VALUES('cat_problem','en','Problem');
INSERT INTO lang VALUES('cat_report','en','Reportage');
INSERT INTO lang VALUES('cat_satire','en','Satire');
INSERT INTO lang VALUES('cat_misc','en','Miscellaneous');
INSERT INTO lang VALUES('cat_sf','en','Science Fiction');
INSERT INTO lang VALUES('cat_show','en','Show');
INSERT INTO lang VALUES('cat_spy','en','Spy Movies');
INSERT INTO lang VALUES('cat_thriller','en','Thriller');
INSERT INTO lang VALUES('cat_animal','en','Animal');
INSERT INTO lang VALUES('cat_animals','en','Animals');
INSERT INTO lang VALUES('cat_travesty','en','Travesty');
INSERT INTO lang VALUES('cat_vacation','en','Vacation');
INSERT INTO lang VALUES('cat_xmas','en','X-Mas');
INSERT INTO lang VALUES('cat_western','en','Western');
INSERT INTO lang VALUES('cat_westerncomedy','en','Western-Comedy');
INSERT INTO lang VALUES('cat_cartoon','en','Cartoon');
INSERT INTO lang VALUES('db_stats','en','Statistics');
INSERT INTO lang VALUES('stat_counts','en','Counts');
INSERT INTO lang VALUES('stat_ranks','en','Ranking');
INSERT INTO lang VALUES('movies','en','Movies');
INSERT INTO lang VALUES('media','en','Media');
INSERT INTO lang VALUES('compose_persons','en','Composers');
INSERT INTO lang VALUES('director_persons','en','Directors');
INSERT INTO lang VALUES('actor_persons','en','Actors');
INSERT INTO lang VALUES('categories','en','Categories');
INSERT INTO lang VALUES('countries','en','Countries');
INSERT INTO lang VALUES('stat_categories','en','Categories (used/all)');
INSERT INTO lang VALUES('stats','en','Statistics');
INSERT INTO lang VALUES('dl_pvp_latest','en','D/L latest version');
