#include <iostream>
#include <string>
#include <unordered_map>
using std::string;

void countingSort(string array[], int length, size_t characterAt){
    std::unordered_map<string, int> codeFor = {
        {" ",0},{"-",0},{"'",0},{"À",1},{"ā",1},{"Ă",1},{"ă",1},{"á",1},{"æ",1},{"Æ",1},{"à",1},{"a",1},{"A",1},{"Ä",1},{"b",2},{"B",2},{"c",3},{"C",3},{"Ç",3},{"ç",3},{"d",4},{"D",4},{"e",5},{"E",5},{"ê",5},{"ë",5},{"è",5},{"é",5},{"È",5},{"É",5},{"Ê",5},{"Ë",5},{"f",6},{"F",6},{"g",7},{"G",7},{"h",8},{"H",8},{"i",9},{"I",9},{"¡",9},{"Ì",9},{"Í",9},{"Î",9},{"Ï",9},{"ï",9},{"î",9},{"ì",9},{"j",10},{"J",10},{"k",11},{"K",11},{"l",12},{"L",12},{"m",13},{"M",13},{"n",14},{"N",14},{"ñ",14},{"Ñ",14},{"o",15},{"O",15},{"ô",15},{"ö",15},{"ò",15},{"ó",15},{"Ò",15},{"Ó",15},{"Ô",15},{"Õ",15},{"Ö",15},{"p",16},{"P",16},{"q",17},{"Q",17},{"r",18},{"R",18},{"s",19},{"S",19},{"t",20},{"T",20},{"U",21},{"u",21},{"v",22},{"V",22},{"w",23},{"W",23},{"x",24},{"X",24},{"y",25},{"Y",25},{"Ÿ",25},{"ý",25},{"z",26},{"Z",26}
    };

    string *newArray = NULL; int *arrayOfCount = NULL;

    newArray = new string[length];
    arrayOfCount = new int[128];

    for (int i = 0; i <127; i++){ //sets all counts to 0
        arrayOfCount[i] = 0;
    }
    for (int i = 0; i <length; i++){ //counts each unique character code 
        arrayOfCount[characterAt < array[i].size() /*if character exists*/ ? (int)(unsigned char)array[i][characterAt] + 1 /*find character code*/ : 0 /*code of 0*/]++;
    } 
    for (int i = 1; i <127; i++){ //finds index
        arrayOfCount[i] += arrayOfCount[i - 1];
    }
    for (int i = length - 1; i >= 0; i--){ //creates new array using new index
        newArray[arrayOfCount[characterAt < array[i].size() ? (int)(unsigned char)array[i][characterAt] + 1 : 0] - 1] = array[i];
        arrayOfCount[characterAt < array[i].size() ? (int)(unsigned char)array[i][characterAt] + 1 : 0]--;
    }
    for (int i = 0; i < length; i++){ //outputs new array to old array
        array[i] = newArray[i];
    }
    // avoid memory leak
    delete[] newArray;
    delete[] arrayOfCount;
}

void radixSort(string unsortedArray[], int length){
    size_t max = unsortedArray[0].size();
    for (int i = 1; i < length; i++){
        if (unsortedArray[i].size()>max)
            max = unsortedArray[i].size();
    } //get number of most characters
    for (size_t characterAt = max; characterAt > 0; characterAt--){ //goes backwards to sort last character to first
        countingSort(unsortedArray, length, characterAt - 1);
    }

}

int main(void) {
    string data[] = {"itinerancy","yoke","oviparous","esnecies","taillessness","sewel","trilobate","penury","tract","curiousest","tivy","animisms","canings","magnets","mercerised","invalid","hugeousness","agreeable","unifoliolate","indefinitely","evaporates","hyperthyroidisms","mongrelisers","antirealisms","guilelessness","demonological","areaches","umbrae","smokepot","rusticating","noncaking","jostlings","enwrapping","electrified","invigilator","eldorados","mochiness","deliberateness","epistoler","formidablenesses","psychedelias","dated","rhuses","surmistress","lioncelles","piperidine","celebrative","jaggy","laufs","pantrymaids","bluefin","discandie","sprawliest","mentalistically","recent","negative","acting","frustrates","pumpion","porta","codeveloper","macroglia","stratigraphy","pinkishnesses","informal","commixtion","abulic","cacotopias","syphilophobias","anticellulite","congesting","waymark","white","dentitions","catadromous","enraged","raja","poromerics","assertoric","downforces","bagarres","terminated","angerly","gillyvor","insolated","palavering","bowrs","foodways","featureless","improvers","hypotonicity","tailspinning","catneps","vaporizable","mucoids","ravigote","monopodially","romanisations","teachie","medicalized","dict","tondi","champleves","unibrow","unparalleled","battilling","ferial","tracasserie","bobbly","trituberculism","tarantaraed","schizogonous","clift","vulned","vernalisations","ricercares","intermediates","zelkovas","solacing","galactose","babkas","lindens","carcinomatoid","manner","hermetist","refractaries","needlessnesses","gonopods","hotly","fermentor","tunablenesses","musting","nonfeminist","noctambulisms","miswrites","intertextual","baltis","appendicitises","fabulizing","misfeasors","pecorinos","harems","unpersons","nobler","muumuus","funfest","prescriptively","bittercress","grandiose","dailiness","pituites","nonalphabetic","microbiologies","tennists","multileveled","ringsides","antihijack","southernised","retrain","blungers","unpopularly","loonie","nonarts","splurger","rhabdoids","berme","antipesticide","modists","overriding","absorbant","serdab","skepticalnesses","confervoids","gwyniad","undecisive","deactivating","unchangeably","swoops","foutres","colcannons","steamie","gluciniums","verminates","kiaat","madronos","coagulums","guardrails","charoseths","mongeese","englutting","fatten","stimulant","ongaonga","caustical","splendiferousness","annexationists","stratified","terrorisations","mirthless","barquentine","benzidine","tachyarrhythmias","covey","goodish","solemnise","zoograftings","canola","watercooler","sedimentable","joypop","colorizes","melodized","dehypnotising","clamourer","shidder","blissing","blithered","bigamists","freewheel","scaletails","disapplication","familisms","jarldom","calaboose","woodborers","marmoreally","gimcrackeries","plate","sweet","camash","rot","frijoles","cardiomotor","traumatizes","obsession","odals","semifreddos","vivres","tuyere","salvagers","loungewear","followings","hispanicises","plook","canvasback","spiritualities","splenizations","caponizing","scalpriform","bushers","roguer","mezzes","deathlinesses","reified","intussuscepts","thermophiles","gymps","marcelling","enforcer","erotics","gelatinously","agamids","pea","whereases","dalliers","verboseness","exigeant","carmagnoles","kent","ave","infracted","gynaecocracies","phonoscope","labouring","assevers","pinups","patroclinal","sketchiest","toying","ichthyolatrous","unparallel","counterraided","quantical","petre","previewing","outschemed","hippen","emblemized","hypertensive","surrebuts","tetragram","clumsinesses","nonohmic","bestraddle","maxillulae","ashfalls","eventualises","archbishop","anesthesiologist","pannicle","restump","scrumptiously","tyrannises","pauseless","sortation","nazifying","parvoline","testings","degenerates","asepticized","underinvestments","chintzes","executively","latosols","degradability","escarpment","bearbine","archerfishes","heretrix","reactivate","dithery","schorlomite","camelhairs","verites","dialogist","snuffy","immunizes","dioestruses","citronellas","stied","ungirded","torturings","philanthropoids","armistice","leucocytes","proposition","moratoriums","ulteriorly","stylise","flavonols","bytalk","diastrophism","avianising","halakahs","dilates","taxeme","naphthalize","cynosures","swingboat","sleided","scrabbed","fenniest","lineages","illegiblenesses","macarize","speculatist","unloves","overhating","dartrous","unmarred","mottiest","yaupon","miskicks","caldron","pontific","decamped","rubricating","marconied","carvels","jousters","whemmled","cranes","nonprofits","inceptives","rodster","weared","barometries","sylphiest","zootropes","domestication","kaies","critics","airning","untwilled","phonograms","anticigarette","raitas","shell","quinquecostate","croc","economizes","vanward","equitableness","illaqueating","dispence","paints","uphangs","solemnises","renegate","epimeres","laudatives","untrims","nazifies","puggles","fuckhead","enunciators","cumulet","dubsteps","bludiest","stinko","sepulchres","hells","dysprosiums","bitstock","haanepoot","tutorises","piranhas","uncritically","unacademic","reenergising","crossbreds","blepharisms","ascendeurs","shtickier","expertized","interphases","lieu","zinkiest","aftersales","overpopulates","doggo","venters","upraising","disaggregative","fermions","tridimensional","codein","duchessed","refillable","fraught","manikins","steer","recrudesced","smaragds","microliter","suppressibilities","subsidiarity","glooming","immunosuppressed","squallish","glopping","surveilling","tinseling","boyed","enswathements","albites","thuggisms","weldable","foobar","secretnesses","perhaps","convoying","puddlings","soundscape","camorrist","underglaze","exchequered","oculi","batoons","vocalnesses","aguised","glisteningly","hawsepipes","greenockite","cyclothymes","riesling","coralliferous","tideway","gabelled","ferroelectricities","autophagia","apedom","umfazis","merse","sestons","stablishes","whitewasher","contemporaneity","convinced","isochroous","lattices","hammerless","ephorate","alidade","unrifled","eluded","cassoulets","daedalic","velocity","unnilseptium","resmelts","requicken","hazmats","cauterisation","smooging","spiceberries","cultivabilities","perjinkity","dissilience","myoglobin","epithermal","intwinement","shirralees","alkalinising","bloodless","junketeer","tablesful","blears","acolytes","profaners","lateener","residences","autochthonies","broadcast","culturable","mudged","crimewave","openness","calvados","skimobiles","handsturn","confounders","presenting","crystal","salaciousnesses","exteroceptor","inaudibly","touchbacks","snipes","recumbences","undiscernedly","nonstatives","deforcing","absurdism","corivals","keelhauled","iridium","noninclusions","wadsetter","agelessly","reconceptualized","quadrisects","subsatellites","changelessness","beth","kaffeeklatsch","bourkhas","correspondence","unfact","grandpapa","kudoses","hallooing","apace","stigmatisation","cockshy","bayou","inverts","slosh","enurns","sootflakes","subcontractings","unprejudicedly","tikes","shod","kinetochore","metalwork","escalators","jaghirs","synaposematisms","fubsier","mangel","alcoholicity","recompense","hedgehopper","phonocardiograms","sentience","scoinsons","paylist","editorially","concentrated","reedy","miasmatic","pepsinate","diaconicon","seismonastic","scalages","prelate","resensitizes","herden","fishified","impotence","credibilities","kitenges","superventions","intervales","randomization","siamangs","plumbums","tuberculomas","talmuds","orchidology","riders","boyishly","buccaniering","boysenberry","antibusers","antivivisectionists","consumedly","antiseptically","ideopraxist","marcellas","melted","orthohydrogens","tonsillitides","blue","wrinkled","keddahs","bromelain","tsetse","undesirabilities","codename","sylleptically","phacolite","crocosmias","wonnings","wifelike","ootid","inferrable","panelized","gawked","coppicing","sophistications","befooled","onychocryptoses","overinflates","judder","constringed","xantham","aquicultures","chagrins","pseudosolutions","discoursed","hydrographers","there","speired","nematocide","unalike","omenta","gunfighter","mailgrammed","timbers","nonsignificantly","ar","cryptanalysts","mistitling","acanthocephalan","bebungs","crofters","debrides","yesterday","scazons","toddling","newsing","conjurement","polysynthesisms","scrutinizingly","airdrawn","oba","patchockes","missilries","dewaxing","vertebrae","occluders","quadrans","shampoo","reamiest","hootiest","pentalpha","rattening","homonymic","spheroidised","whelps","bookman","prewrap","anapestics","nitrosyl","picometer","sprod","recaptions","glassmaker","dyspraxic","eloigner","implicating","feudists","spacers","vulns","overextravagant","titubations","sutras","interdiffused","marrers","trimix","narceen","topgallant","chromatogram","warrantors","spain","workaholic","dayflower","grabbiest","hearsed","misdescription","hetairas","exclusivists","parrocks","cecropin","appreciativeness","carageenans","lungan","abraiding","cemeteries","defervescency","desensitizer","perniones","shamus","reactionaries","forfochen","shipworm","diazinons","fiberglassing","spoors","mussitated","contrabandists","kamacite","moony","redback","turpentines","cuspidores","lenition","exons","mawkins","midstreams","outtrumping","expositorily","brotherhoods","absorptivities","unregarding","gytes","mandrill","disbarring","shirralee","aerobiologists","pends","steeves","adjectivally","sidetracks","herald","sohurs","disaccommodates","consolidating","protoplast","creation","sawdusty","mazaedium","tracklaying","lissomly","copycat","vertebral","weblogs","hydroxylapatite","hermitic","zerdas","fervor","noxes","artificialness","mama","warners","sequelises","icepacks","annexationisms","douses","iching","cadaverousness","blowback","recondite","gallica","ageratum","pretexted","contumacities","poilu","decumbiture","incessant","cisternal","cebids","fanfares","empoisoning","christeners","gab","enantiomorphy","wire","poonac","zemindars","groaners","guerrillero","windsail","susceptivenesses","phrasing","interglacials","brachycephalous","fillet","anhedonic","mucilages","costotomy","readorns","koraris","unproperly","gam","lovesome","preflighted","pourtrayd","representable","surfeits","antiwhite","albespine","subtropics","immortelles","builded","vanessas","cicada","scapaing","esquisses","sandpaper","dements","slangs","tuna","mobled","pulmobranchiate","nidus","rubboard","trachitises","orthopedical","drongos","interchurch","mineralogising","periplus","bwazis","prussiate","ergotamines","schwarmerei","barnstormer","influentially","cornua","puerilism","sidler","enactory","hyracoideans","restructured","antiphrases","anglicise","teleonomy","heinous","brandade","mylonitised","collectibles","conducive","banderilla","neurolemma","chalone","gaingivings","monoptote","placating","hemagglutinating","prewriting","rockwater","medicalizes","interculturally","nereid","ennuied","lyings","rescinder","maccaroni","pledges","picote","alays","parping","powellize","overexaggeration","peined","liquefaction","president","tragedienne","trituberculy","doorframes","poboy","aleuronic","prelacies","unprettinesses","dishdashas","issuant","dumpishness","spyings","firepans","cathood","uricotelism","nobilitate","antitumors","motorized","narcomata","autorickshaw","trezes","otorrhoea","autotheist","schematisations","protreptical","individuum","pretends","coincidency","mummification","iceboat","psychochemicals","chromised","mixdown","spinnerule","overservicing","hemopoiesis","gulleries","pluralization","whistling","disponged","cueings","winterizes","rednecks","hypermasculine","bitartrate","chorioallantoides","unborne","booklets","ataraxias","caregiver","profitability" };

    radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        printf("    %s\n", data[i].c_str());
    }
    return 0;
}