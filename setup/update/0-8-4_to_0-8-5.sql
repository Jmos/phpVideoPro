# ========================================================
# Updating Database for phpVideoPro from v0.8.4 to v0.8.5
# ========================================================

# prepare default lang update
DELETE FROM lang WHERE lang='en';

# version update
UPDATE pvp_config SET value='0.8.5' WHERE name='version';

# New CD/DVD labels
INSERT INTO label_forms
  (vendor,product,description,type,unit_id,h_dist,v_dist,width,heigth,leftm,
   topm,cols,rows,sheet_id) VALUES
  (3,'Standard','CD/DVD Etikett','CD/DVD Etikett',3,3,11.9,11.9,11.9,11.9,1.1,
   2.4,1,1,1);
INSERT INTO eps_templates
  (27,3,'Action','action_cddvd.eps','common_cddvd.ps',0,0,468,474);
INSERT INTO eps_templates
  (28,3,'Comedy','comedy_cddvd.eps','common_cddvd.ps',0,0,468,474);
INSERT INTO eps_templates
  (29,3,'Doku','docu_cddvd.eps','common_cddvd.ps',0,0,468,474);
INSERT INTO eps_templates
  (30,3,'SciFi','sf_cddvd.eps','common_cddvd.ps',0,0,468,474);
INSERT INTO eps_templates
  (31,3,'Simple','simple_cddvd.eps','common_cddvd.ps',0,0,468,474);
