import os

if __name__=="__main__":
    os.system("msgmerge --update --no-fuzzy-matching ./po/zh_CN.po ./po/template.po")
    
