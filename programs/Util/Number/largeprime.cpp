#include <bits/stdc++.h> 
using namespace std;

//2^62以上,2^63未満の素数（メルセンヌツイスタで生成し、ミラーラビン素数判定で判定）

typedef long long ll;
vector<ll>  large_prime = {
7013813588750972951LL,
8929143633738088283LL,
4837909145654321621LL,
6819033938186690237LL,
5107328697654825071LL,
6984644639313321301LL,
7981742035558655513LL,
5012529736381582537LL,
7764346403316436763LL,
8785404510772599077LL,
8633456453244188413LL,
8587500876086749187LL,
8017272978710360107LL,
6848291763666747881LL,
7139167450962790259LL,
8022954163009322189LL,
9143891457239649371LL,
8640922035650948299LL,
9029343276445700647LL,
8247176853938049239LL,
7589254429921819817LL,
5142516679001679589LL,
5200611458731395041LL,
6931502703227627159LL,
7145937761510663699LL,
4849099313219578013LL,
9015674531757303521LL,
7430593255756166231LL,
6483121789316985157LL,
5612396471008553777LL,
4901127230831139299LL,
5779680333331304651LL,
9006353196306823859LL,
4754674176471728863LL,
9219340183041231127LL,
5967335078443760453LL,
9100621791822219299LL,
7616701924342413059LL,
5191774864029211589LL,
5022039611605491427LL,
5597646246477928369LL,
7457632774518150713LL,
8460632906330256497LL,
8001307628859017483LL,
5306167470601731623LL,
7920367127687687891LL,
7420044918905548313LL,
5618979528314011297LL,
8076635488546249913LL,
5398380866436344819LL,
9040914722879141029LL,
9156263051223796567LL,
6135987571944723217LL,
8933558547641200621LL,
7213100843262423313LL,
6017740772320762081LL,
6804539460902454611LL,
8224461109916797373LL,
8342997797836230007LL,
7011432727683265753LL,
7739770433352518501LL,
6714203327974546709LL,
8583925205256722147LL,
7733583566239087433LL,
8423720709857848259LL,
8736904920117197839LL,
4617100586804013629LL,
8123115237385267487LL,
8920184122845828991LL,
9017263294273365137LL,
5784808042509227969LL,
8640396390857460917LL,
8846111887552109617LL,
6810623910863150737LL,
4803317168339039033LL,
8187881930037594377LL,
8215346658138821021LL,
8260442363037042569LL,
8810854434869862097LL,
8234254578818535601LL,
5696016210000561587LL,
8709213703755617369LL,
7726461746213925103LL,
6177784779457183931LL,
4813014832945773617LL,
7254760331287390217LL,
5695822716055175989LL,
9172030606079157779LL,
8258500973652362647LL,
7877464087566988151LL,
6583877186172403441LL,
6065550745138824157LL,
7709206303066783649LL,
7630529635328379173LL,
6625990745891156617LL,
7285152939963258193LL,
7311295935078012173LL,
5311272474576456299LL,
6152905086073624079LL,
5314053834394660573LL,
5825362042760893901LL,
4952514123032008849LL,
4705123061672168467LL,
8989755355083407897LL,
6949817007802481509LL,
6812856933576589351LL,
4999509926415897773LL,
5203208964677984321LL,
4883155690616520467LL,
6793021252555336177LL,
6625457965798001669LL,
5952239059922177137LL,
6294459300254885843LL,
6252396358508166721LL,
8297573882134511189LL,
8045796912105283963LL,
6962411862273697469LL,
7470215265591779447LL,
5139628747014800411LL,
6918823534276948423LL,
8760217895886058103LL,
4725057635957906167LL,
7872745710573010901LL,
5723391353683937261LL,
7081403340634767181LL,
9145356668416385413LL,
5796740506540544419LL,
8228602398564263759LL,
8877053252300163031LL,
8747138847133885267LL,
7885226045569131421LL,
6661275513619570499LL,
8657892089919233929LL,
6122778800946507841LL,
7623573708607568977LL,
6336766264195471661LL,
6284014325178245473LL,
9213367125151656241LL,
8678954018017823753LL,
8242715197820292143LL,
5124784035605417609LL,
8492354058850692067LL,
7390606212594987847LL,
8006794368329558567LL,
5878868478587039729LL,
7887359791949235749LL,
8025748151086370057LL,
8217480503644095923LL,
5209187599622958607LL,
9220958317947549179LL,
9203307645064254017LL,
5849165710422885769LL,
5969191640084274097LL,
7660816085484721759LL,
6323340772358837099LL,
6241506403998443323LL,
4908805206656714089LL,
7518452223432417139LL,
5212753142492682271LL,
7794170450792729083LL,
4901359913548277293LL,
4795647367847918633LL,
6083996098164256439LL,
5149013849730250559LL,
5201390806840588909LL,
5478022215152119921LL,
5198114945398876301LL,
7396011212049831611LL,
9106682065371256517LL,
5991185923900143761LL,
6412327533424051637LL,
8217005351409764587LL,
5410150656798642577LL,
4784213637458966387LL,
7478501588588754209LL,
5918676619641341681LL,
8850282301813588169LL,
6535680458695841723LL,
7475145350604611861LL,
9057009971065392673LL,
7823816817843428687LL,
4690914069696344023LL,
8700728378538841241LL,
5665124531426062873LL,
9076209581237173511LL,
8336313658883339039LL,
5146214606337556711LL,
7878450878079556303LL,
7704557735392299857LL,
7587514762759267601LL,
6782258332122247379LL,
8634994165822073641LL,
7012912581286196401LL,
7567557630524690081LL,
7449125240757391129LL,
6322241097109802779LL,
5336638072195131509LL,
5671232477412152423LL,
8164219602499802069LL,
9038072477467440857LL,
8898655496599664863LL,
6491393192590671649LL,
9020942840236855193LL,
7379404600531778173LL,
6575649419978200157LL,
7759549199103126619LL,
8052465431268923053LL,
6309643175720980763LL,
4834781126404810597LL,
6199716619483751503LL,
8165690699894425069LL,
6621248036825350207LL,
6753669538762997579LL,
6537059989556165119LL,
6440388344883076613LL,
6654558960850375171LL,
6625325726273604809LL,
5022506832955991273LL,
6841943020739004953LL,
4708421537415362959LL,
9059574703230216731LL,
5649030319382567197LL,
8136530374367808557LL,
9185304997789506403LL,
5310734871313200559LL,
6467854809279477629LL,
5664862672970384341LL,
4686770919638180591LL,
7043847282015442867LL,
8009085529773106391LL,
7436529471513075347LL,
8416335196705493441LL,
5859931961058478507LL,
5181167779502562473LL,
4932706039456108871LL,
8306882871845418989LL,
5740647712805813111LL,
6236128282564094669LL,
4820648019039463379LL,
4915578729741743929LL,
6914776352688366719LL,
4766942059822547009LL,
8501100823048622119LL,
6991553260025389537LL,
6985014829191979243LL,
4851566565938921489LL,
7482378076116646321LL,
8015428433874688061LL,
4918862520601735483LL,
5325003971768290499LL,
7755417080683660133LL,
7147190180381983289LL,
9108526497689116241LL,
6131589673760112941LL,
7676080045499539073LL,
9053249734854997457LL,
5286435210189225109LL,
4696368186779975767LL,
7767273002698502857LL,
8566033810000077371LL,
5840450233218043493LL,
5919080186373001117LL,
6228455504958319439LL,
5460569900773567213LL,
7917227806777363561LL,
7999503976138073869LL,
6993234870316729709LL,
6703135846653345259LL,
6797481620365289239LL,
7666961703528360041LL,
8881295176713628807LL,
6950127443032739047LL,
5287717295536445573LL,
8490862688155185869LL,
7632558676296922999LL,
7780149488696328721LL,
9062322111356312129LL,
8670050192015879957LL,
7873621228173327677LL,
4976266627617184517LL,
5046542504222568061LL,
8531296799170719209LL,
7525757251121085829LL,
6194223411881018519LL,
7430701500017476463LL,
6297981646718479181LL,
8189026838495337733LL,
5201382154197324517LL,
7787199168943349473LL,
6608811707673064661LL,
8154526277698617253LL,
6073980178237026431LL,
7088170165697184407LL,
7560654648027471983LL,
6669459887605847603LL,
8311664466956403071LL,
8939385722965862939LL,
7080453587355931591LL,
8201947971601869899LL,
8305661454970414609LL,
4753771326628740679LL,
5749323409948242769LL,
4736311897280511809LL,
5824848274137030079LL,
8839682243890810073LL,
7038990319954573273LL,
6587041280188015253LL,
5648889656367389519LL,
7771163283001194149LL,
8711336809264160651LL,
7190067766247151899LL,
8613754731294213587LL,
8744495458659934529LL,
5534660580378345697LL,
7587485412374103617LL,
5100493845728285861LL,
7567203103539225551LL,
8384667350742587213LL,
7141226421507534289LL,
6891317277310356043LL,
5176962244905118037LL,
5712350796164464211LL,
8766038724981764353LL,
7319909735724172247LL,
4930018415629755229LL,
6227994806878941647LL,
8881323713954782459LL,
5996910747052847309LL,
8671228518156490543LL,
7624246096415150737LL,
8102721722843660749LL,
6066506415093464677LL,
8439931295039659013LL,
4789821237192695831LL,
7347854331544823513LL,
7054319303948878751LL,
5263991178053108129LL,
7885481036523549089LL,
8556197715769744423LL,
8210000787262616647LL,
6469061220578324363LL,
7664964460520105003LL,
8482393062940817971LL,
8468186039026396411LL,
5489382541088737523LL,
6165117479740491253LL,
5069955462674524883LL,
4744705286079844873LL,
9217453283481019663LL,
4752476659358186443LL,
5456708532871734493LL,
7850329676618783399LL,
8637063049107676759LL,
6499551822915660493LL,
8910529031227561973LL,
5067993607677299861LL,
8257588043962453319LL,
7610241041425224347LL,
6599377281043648471LL,
6615403067459131697LL,
5157339951856264607LL,
4863865475381224687LL,
6389449950338616361LL,
7445879606462862937LL,
7622770744925838037LL,
4845945411403266593LL,
8498463351480768241LL,
5634964875616745983LL,
5157738985600084333LL,
6251516095506849901LL,
5284235814367670653LL,
7848226632600639451LL,
8580273195036886657LL,
8967312495578251181LL,
6482305017482925271LL,
5094398846766227741LL,
8841993484617188899LL,
5493617275220151587LL,
8306898961632001457LL,
5242898493073562663LL,
6450131999425814489LL,
9038310046199410127LL,
6440070112033306907LL,
7087556504781808789LL,
4854722319958340993LL,
8215561510805377991LL,
5873258505492688963LL,
8473599082364176457LL,
8728190788583546759LL,
7095021691421765789LL,
4830116067555399067LL,
6291276038986541041LL,
4740146951818395529LL,
6810267376258944511LL,
8422893981540021881LL,
6745618955592656459LL,
6908681671317677591LL,
8871060260743621289LL,
5216664457944225707LL,
6795423785706218297LL,
8253661528917372173LL,
5689057010349870853LL,
6143348668811522827LL,
7092339750950224213LL,
8226894486403711663LL,
7289889470165012509LL,
7867132605318685561LL,
7176779283492884999LL,
4912606453948081753LL,
8973245797196481949LL,
4938415646884862719LL,
6616081292694921823LL,
5867319767089952957LL,
5977869221108032837LL,
5376077386436426801LL,
5387854288106938057LL,
7980800503345789043LL,
7823723776784124179LL,
5592058989900224423LL,
5585151848654562677LL,
7420715728320160381LL,
6246818495242184173LL,
8006690365919931409LL,
7406482263120020117LL,
8697580828059849689LL,
5952502810414092937LL,
5432798843255168071LL,
5714428650265201277LL,
9221508888506934157LL,
8559587311956211397LL,
4742416960729862503LL,
8543901692046198053LL,
5525380718139522059LL,
7554915152236825981LL,
4912545157610363587LL,
6778428934086068141LL,
6637815897816023269LL,
7073126253117701657LL,
7680311634510317771LL,
7183177523978966567LL,
5816659874831397467LL,
5372597558883343093LL,
4999501203748330457LL,
5245864420183022081LL,
7737996183303071417LL,
7336051880835448703LL,
5052606723083222137LL,
8759195491859008051LL,
7117201706764183387LL,
7518663169887366899LL,
7349597856020827487LL,
5477442899857200497LL,
7514159240736555629LL,
7509941924604570317LL,
8542991674033883419LL,
5979896366968198469LL,
5082404290789193579LL,
6393773155475589931LL,
6777646379548651003LL,
9173522536535692297LL,
8308793735057538131LL,
5995881096142452689LL,
4618286894757953413LL,
6517824946245041867LL,
7449307132081043531LL,
7243851992218980709LL,
9115122914108896957LL,
5274465351062545933LL,
7983681771425006279LL,
7995834053327133373LL,
5372075748293536063LL,
9097644766062063983LL,
6542907932801444101LL,
9180188982524333461LL,
5362741197167087273LL,
8038766055423605543LL,
7057865968738459751LL,
6361551965674993697LL,
9031999477397687761LL,
5188080280916264527LL,
9051435443918714617LL,
6593324038526309297LL,
6462379806093329353LL,
5114661185382580679LL,
5937485051879346913LL,
6420408672459507449LL,
5856207763370128919LL,
6330572076294210583LL,
8038845454733926823LL,
8080159036943987263LL,
8938221084918504823LL,
5496581852633943131LL,
8719902446293201747LL,
5880014842771845049LL,
8948012449519856023LL,
5616545987731917253LL,
6970992735116403601LL,
8896665250154893201LL,
8289179226692640533LL,
8809042776884940851LL,
8294733332033182213LL,
6301396186557879569LL,
5737167702520038131LL,
5796393821705262521LL,
6037960900741333667LL,
8372465563540401899LL,
6596508077106302653LL,
6554315693445517411LL,
7903041556469380751LL,
5077521118551855287LL,
4668371151974332753LL,
9162603980044234211LL,
8926600122215064749LL,
7167910223582165009LL,
6539031573971845969LL,
4844107079959171421LL,
9015665305203527563LL,
8767141073923536803LL,
9116635141041099631LL,
5051438241541662107LL,
9039210635170272107LL,
4895189397067358269LL,
7537281297172115101LL,
5439625069049553413LL,
4852956139742132771LL,
6177015057072748139LL,
8296270393584542389LL,
8318888394026323123LL,
6084628449687755309LL,
6971792628764286667LL,
8063801125440805097LL,
8401435083704805119LL,
7250010446337764689LL,
5540257725962497981LL,
6817010734405787473LL,
7342688260195992203LL,
8741283270846142063LL,
6999695157536133119LL,
7788371603414525857LL,
6728804818295600203LL,
5078604901363492979LL,
6831065082145187033LL,
8181946692205057831LL,
6870666908577860551LL,
6933115226704515973LL,
8776182830545574893LL,
8157379319452441327LL,
6084288509276197247LL,
8675751115052193281LL,
6378048719147955467LL,
7332014022701592061LL,
8282750515512197633LL,
7549155116318645009LL,
5572498609359380653LL,
5270524426411313137LL,
5564901989721382019LL,
9179070731971430539LL,
6386207854164096863LL,
7399790423262984707LL,
5191297198126144153LL,
6948335959932341171LL,
8496409846387053301LL,
8558295358296224633LL,
6450260406973140137LL,
9134299117648975357LL,
6039073446795508199LL,
8321610616036452479LL,
4697193114410191697LL,
8185219286616579503LL,
4955819685083927983LL,
6932350465747085609LL,
5027837278602740339LL,
5552271386579884207LL,
5492237646326767519LL,
5769533924778029993LL,
8839128734261722961LL,
8488675595180131469LL,
6297364840244581589LL,
7442334374460810037LL,
6862746280178991311LL,
7962950938353738779LL,
6839681793628941613LL,
5564411775360767143LL,
6834929309241462113LL,
6756499154026811213LL,
6261360903709066399LL,
8127521496670598123LL,
8169301547642290873LL,
9052128559164313261LL,
6475994133232623551LL,
7991716606396954523LL,
7055335031933967629LL,
6910207921233148991LL,
9219642465748201943LL,
7043179563990314417LL,
6702843029315450203LL,
8437700070130497197LL,
7231753409170845749LL,
8165970267595572871LL,
5856744090706348831LL,
4736673419071576327LL,
4876842378918300311LL,
7441040628467689091LL,
5240611531337223529LL,
8665942066317666841LL,
8623374067267234949LL,
4826679474510913573LL,
7610099050985016557LL,
8914276479223651511LL,
7458902436634568243LL,
9200451823753050733LL,
5984472612344574347LL,
5555724127496006579LL,
6820205181690060119LL,
7793141422610082131LL,
4638731452718392499LL,
5405789420695779211LL,
6588171840401388619LL,
5692091005351084793LL,
7351996478525880913LL,
5600374714030927979LL,
5061426123615404407LL,
7365150833741297273LL,
7297808475715062311LL,
4697234889471865337LL,
6586480880474344309LL,
5823298964971214327LL,
8230706547364884041LL,
5689610871229509859LL,
5877139421762689559LL,
7772273234528032583LL,
7013057337469063271LL,
5449844426758704439LL,
6966047640209540329LL,
5228223351143077799LL,
5463952819748639369LL,
4868764588258961909LL,
8869846627845052793LL,
5707704515169660989LL,
5682487284242600357LL,
5203704090622801121LL,
9021629910734608913LL,
4638344471898110107LL,
6281253815370478817LL,
5101639619033961173LL,
8862209492627084309LL,
8350204438410921941LL,
5221465702573728271LL,
8328500714370766637LL,
8322498081962473889LL,
7337132194712867251LL,
8125564718250012443LL,
6755533620575432387LL,
7032475539816290119LL,
7574661868652694311LL,
8370941102181168517LL,
9110556275690755331LL,
6792384714004964639LL,
4976071605575989657LL,
8286269641773812951LL,
5553598882708409353LL,
5111369667202956299LL,
4633356955301924821LL,
9209923560760196803LL,
8158076094545487043LL,
8315295330767726407LL,
7324348041220920389LL,
5988289597525401953LL,
5714248843420164419LL,
7394533005858751121LL,
7853565660642457673LL,
5028951320237703059LL,
7147551842666824013LL,
4643767621338917641LL,
5871953457552297517LL,
8382863764446450281LL,
8378705925304307861LL,
8848324769501690723LL,
7148136108665231389LL,
8752245781827790873LL,
8027099755937962003LL,
5179311998497091417LL,
6802218213655248779LL,
6665074491686127173LL,
8573749517784884747LL,
5364935354929805737LL,
5742927729621034103LL,
6564769674080505133LL,
8734228809342082681LL,
5411837979533712521LL,
5861872821090755093LL,
7289364402527383849LL,
6180981710437149689LL,
6849557699295392321LL,
6631254394232447807LL,
6538066285535055421LL,
6039545827327521893LL,
8680424826913495417LL,
6821361488272762111LL,
7235450352740203127LL,
8442313712619216821LL,
6525476294288148019LL,
5493782218492812193LL,
9145506363815840869LL,
7447025094167476507LL,
8876620815623813851LL,
5631258675864089341LL,
5544442969532446907LL,
7280983504821742843LL,
5172353341176303001LL,
6372637961117560849LL,
8436750602661044381LL,
5234163247228027603LL,
4966849609573250381LL,
5723403859096050443LL,
8036653547567264413LL,
5344545820821108911LL,
8346784628654000761LL,
6897296167665537481LL,
7731169310754010549LL,
6553631934126219389LL,
5433826102979279827LL,
4928840430662713519LL,
7754145362692611781LL,
8125112955143031149LL,
7290943253286483341LL,
5889543394805200139LL,
5409900550495690453LL,
8052687345890684899LL,
6597756578146404079LL,
6577996854802225037LL,
8000319045641076883LL,
5239842344735956387LL,
5350070781210451369LL,
5689656129187622153LL,
4741470738526951031LL,
7088642263130867639LL,
5855225027995780841LL,
6895864640843578277LL,
5748376486337944049LL,
8885980617663401719LL,
7939478018608516049LL,
6945261737783579071LL,
7002765603998673637LL,
7104977189070317237LL,
5057017786299007853LL,
8262173997762673607LL,
5287293766337886689LL,
7325615124896514227LL,
5931983700782886689LL,
7542986181434568223LL,
8361080910509686883LL,
7490935714953318469LL,
5605927637116587029LL,
5247162306886156829LL,
5897124855461200619LL,
5169296569363074433LL,
6037464236220666611LL,
5892798779341112731LL,
5396403678235795921LL,
7480633765706203013LL,
5940690891453530153LL,
5361251856496034347LL,
8770730803475719699LL,
5187648078788783159LL,
4722339421848970309LL,
7261396581083874241LL,
7360287091267784491LL,
5066285550862147519LL,
5047366932685865479LL,
8328671383000301731LL,
8585190315036236243LL,
6204014981506482367LL,
8053947703963796183LL,
8699526798725550413LL,
4919204050853685673LL,
5052809531531938919LL,
8801996452252932347LL,
8489542614373648631LL,
5334637079608429303LL,
5739202312470781657LL,
6963920115890067067LL,
7849273624526913911LL,
8063385147416010449LL,
5166448824082731799LL,
4632571961743929431LL,
8960542846511132743LL,
5108410091630293729LL,
5730963051592394101LL,
8298725794513696319LL,
8088123449539366819LL,
7761824631895758503LL,
6359270228416951919LL,
6575497863339838513LL,
5700611269248268277LL,
7142372386230182713LL,
5238303718665033689LL,
5351871124705551869LL,
8097941577695698159LL,
8828923006120609127LL,
5916172764356675687LL,
6615414894088496477LL,
8137745475900138361LL,
6032257906674040799LL,
8592598997928974117LL,
4951644645394223213LL,
4868684641381995619LL,
5154523963672077391LL,
8672127369945271781LL,
8434351943838058351LL,
4647294625417288423LL,
8613148056030390703LL,
4697395867465307257LL,
8217388279216756811LL,
7527006876280803299LL,
7070622809731371959LL,
5428477295970726623LL,
8200544959028592419LL,
5750226243560080019LL,
8551745310525782867LL,
8048632442302304477LL,
9062284832098594091LL,
9019943391559567067LL,
7047077916970170011LL,
9151197589307047517LL,
8159750500506992833LL,
8026548284969094007LL,
9061992944714686657LL,
8083161046677273961LL,
8983730255018279099LL,
5388551741783021377LL,
4678656014345278607LL,
5180246346040107809LL,
9203990492181247171LL,
7193888859067719587LL,
6312276089004261899LL,
7732633946131044077LL,
7828773772137572861LL,
4878787525163732143LL,
6279597483732537143LL,
5919843722020977167LL,
6989731025444916493LL,
4738276507345890683LL,
6546311304747576749LL,
5476459481193426403LL,
7179141445373915291LL,
5518376186312199233LL,
8194787875834553743LL,
8131888944220546069LL,
4753677056736251747LL,
5858313216410984561LL,
9187840771264299383LL,
9111357741160296397LL,
5712467750817074341LL,
8847527987891443817LL,
8919818539835377543LL,
7561030283025685469LL,
6081569677030792561LL,
9210803261623267313LL,
7247459415412421743LL,
4773470547823278517LL,
8708190398530697069LL,
5782114800400798331LL,
9030577944606182149LL,
6277589706040497121LL,
8118944749618714273LL,
4896421476231785639LL,
6258525143427762397LL,
8040954739885613951LL,
8277420297580585057LL,
6030031612963834453LL,
4670604855265563161LL,
6639582823350702961LL,
5539750010013626423LL,
7288335654861816377LL,
4757674102943390899LL,
7738523235872759753LL,
8310246536795994793LL,
5801724707770226953LL,
6958711724761671379LL,
6783117576342647473LL,
8482151511172456739LL,
8170875526210194047LL,
5765356808656535221LL,
6876575156535540011LL,
5364809337264003251LL,
5785746595982683339LL,
6861618860302464359LL,
6725847837854836511LL,
4708848700355023417LL,
8280438605875876681LL,
7212945152161825711LL,
6587773016106302453LL,
7453894511335975561LL,
5460109576371529241LL,
8669394589782701603LL,
7685920510354241527LL,
5576178410165209321LL,
8361237327401922773LL,
5441020889401489507LL,
6648545397584431043LL,
6590478943310119843LL,
5925605689452359641LL,
8492276098842694637LL,
4665485546188713629LL,
6302392502850321187LL,
8468319963905259083LL,
6258556376742558563LL,
8398833890143909607LL,
8949910792174700539LL,
9091360436475838903LL,
8346709042285508371LL,
6324013938548763433LL,
8470464298041948073LL,
6246059222830323101LL,
5063411883312239573LL,
7440192928512295751LL,
8833729787633282507LL,
6269296773324999313LL,
6546146382696368947LL,
8754700715061330077LL,
6819846166081551973LL,
6775341621146730253LL,
6611861863186085029LL,
7236391847036999737LL,
5427477452747752447LL,
7295184230216517847LL,
5303495867775704993LL,
5043954852779678707LL,
8251180091562192481LL,
5383769688014773141LL,
6474844436182623647LL,
7733481676425466981LL,
5404008137153802191LL,
4637345355559528289LL,
6992780279521432303LL,
4670758269089317739LL,
8806730472239827733LL,
5049399565568064043LL,
5236043656338518533LL,
8907851275090032677LL,
6280528340070175351LL,
7519682725996563713LL,
6033032352308273629LL,
5805203327889926561LL,
6202243731432528799LL,
5414668105242001393LL,
8169381839243498143LL,
8621332495246224511LL,
5749972876919407427LL,
9053891998034603129LL,
8361007984953923311LL,
8764115326115738671LL,
4740918372342661787LL,
4991009325263597491LL,
7521384422128731169LL,
7002605753240384537LL,
8336546281001101367LL,
6695131430037330251LL,
8260368201602714311LL,
7865788158588775463LL,
6796582502339154253LL,
9065368538341236923LL,
8918598717705750323LL,
5798741834120834617LL,
8353955141276676713LL,
5075434545043487011LL,
7929693469643547617LL,
7735489206214220699LL,
8094052490764707487LL,
5631570579878720987LL,
8790674683457082107LL,
7179599952785356363LL,
6272867512704165019LL,
7784530989173771353LL,
6527503151398487173LL,
8469268344672786881LL,
7013861746716058237LL,
5885198830634329001LL,
7015058304637177903LL,
7861168600045349483LL,
5694627306837985517LL,
6278665057641644939LL,
4739526910475428789LL,
7684962501416359079LL,
6464358882511979357LL,
8467495480196278261LL,
6000220239666661829LL,
8748372673839724301LL,
4818013642422184249LL,
5753616592546280533LL,
8024552328872606707LL,
7311014601968494259LL,
5673463035016148629LL,
7028717141187720101LL,
6273338921232942737LL,
8572791088025685877LL,
4780206464177543401LL,
7450154088050737171LL,
5699344443081462653LL,
};