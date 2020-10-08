<h1><a id="user-content-bluetooth-адресная-матрица-на-arduino" class="anchor" aria-hidden="true" href="#bluetooth-адресная-матрица-на-arduino"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Точечная сварка на Arduino</h1>
<a href="https://youtu.be/iuXaeCmEXaY" rel="nofollow"><img src="https://raw.githubusercontent.com/HamsterTime-r/SpotWelder/main/preview.jpg" alt="prototype video" style="max-width:100%;"></a></p></a></p>
<p><a id="user-content-chapter-0"></a></p>
<h2><a id="user-content-описание-проекта" class="anchor" aria-hidden="true" href="#описание-проекта"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Описание проекта</h2>
<p>Светильник на основе адресной светодиодной ленты с различными эффектами
Страница проекта на сайте: <a href="https://alexgyver.ru/gyverlight/" rel="nofollow">https://alexgyver.ru/gyverlight/</a></p>
<h4><a id="user-content-особенности" class="anchor" aria-hidden="true" href="#особенности"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Особенности:</h4>
<ul>
<li>Управление одним энкодером</li>
<li>Возможности:
<ul>
<li>Установка времени T1: предпрожига</li>
<li>Установка паузы P: между импульсами</li>
<li>Установка основного времени T2: прожига</li>
</ul>
</li>
<li>Управление:
<ul>
<li>1х нажатие энкодера - вход в меню</li>
<li>Прокруткой энкодера - выбираем нужное значение времени предпрожига T1:</li>
<li>1х нажатие энкодера - переходим на P:</li>
<li>Прокруткой энкодера - выбираем нужное значение паузы между импульсами P:</li>
<li>1х нажатие энкодера - переходим на T2:</li>
<li>Прокруткой энкодера - выбираем нужное значение времени основного прожига T2:</li>
</ul>
</li>
</ul>
<p><a id="user-content-chapter-1"></a></p>
<h2><a id="user-content-папки" class="anchor" aria-hidden="true" href="#папки"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Папки</h2>
<p><strong>ВНИМАНИЕ! Если это твой первый опыт работы с Arduino, читай <a href="#chapter-4">инструкцию</a></strong></p>
<ul>
<li><strong>libraries</strong> - библиотеки проекта. Заменить имеющиеся версии</li>
<li><strong>firmware</strong> - прошивки для Arduino</li>
<li><strong>schemes</strong> - схемы подключения компонентов</li>
</ul>
  <p><a id="user-content-chapter-2"></a></p>
<h2><a id="user-content-схемы" class="anchor" aria-hidden="true" href="#схемы"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Схемы</h2>
<p><a target="_blank" rel="noopener noreferrer" href="https://github.com/HamsterTime-r/SpotWelder/blob/main/schemes/scheme_1.jpg"><img src="https://raw.githubusercontent.com/HamsterTime-r/SpotWelder/main/schemes/scheme_1.jpg" alt="SCHEME" style="max-width:100%;"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/HamsterTime-r/SpotWelder/blob/main/schemes/scheme_2.jpg"><img src="https://raw.githubusercontent.com/HamsterTime-r/SpotWelder/main/schemes/scheme_2.jpg" alt="SCHEME" style="max-width:100%;"></a></p>
<p><a id="user-content-chapter-3"></a></p>
<h2><a id="user-content-материалы-и-компоненты" class="anchor" aria-hidden="true" href="#материалы-и-компоненты"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Материалы и компоненты</h2>
<h3><a id="user-content-ссылки-оставлены-на-магазины-с-которых-я-закупаюсь-уже-не-один-год" class="anchor" aria-hidden="true" href="#ссылки-оставлены-на-магазины-с-которых-я-закупаюсь-уже-не-один-год"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Ссылки оставлены на магазины, с которых я закупаюсь уже не один год</h3>
<ul>
<li>Arduino NANO <a href="http://ali.ski/e6Fgi" rel="nofollow">http://ali.ski/e6Fgi</a>  <a href="http://ali.ski/4_s6VB" rel="nofollow">http://ali.ski/4_s6VB</a></li>
<li>Сенсорный модуль <a href="http://ali.ski/anaje" rel="nofollow">http://ali.ski/anaje</a>  <a href="http://ali.ski/sZnCo" rel="nofollow">http://ali.ski/sZnCo</a></li>
<li>Лента <a href="http://ali.ski/7JZPFu" rel="nofollow">http://ali.ski/7JZPFu</a></li>
<li>Резисторы (220 R) <a href="http://ali.ski/Ony1Q7" rel="nofollow">http://ali.ski/Ony1Q7</a></li>
<li>БП 5 Вольт <a href="http://ali.ski/1t4zpW" rel="nofollow">http://ali.ski/1t4zpW</a>  <a href="http://ali.ski/mCNnFW" rel="nofollow">http://ali.ski/mCNnFW</a></li>
<li>Ступенчатое сверло <a href="http://ali.ski/2pMIX" rel="nofollow">http://ali.ski/2pMIX</a></li>
<li>Проводочки <a href="http://ali.ski/Q7OF3" rel="nofollow">http://ali.ski/Q7OF3</a>  <a href="http://ali.ski/9xvYq" rel="nofollow">http://ali.ski/9xvYq</a></li>
</ul>
<p><a id="user-content-chapter-4"></a></p>
<h2><a id="user-content-как-скачать-и-прошить" class="anchor" aria-hidden="true" href="#как-скачать-и-прошить"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Как скачать и прошить</h2>
<ul>
<li><a href="http://alexgyver.ru/arduino-first/" rel="nofollow">Первые шаги с Arduino</a> - ультра подробная статья по началу работы с Ардуино от 
AlexGyver, ознакомиться первым делом!</li>
<li>Скачать архив с проектом</li>
</ul>
<blockquote>
<p>На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка <strong>Clone or download</strong>, вот её жми, там будет <strong>Download ZIP</strong></p>
</blockquote>
<ul>
<li>Установить библиотеки в<br>
<code>C:\Program Files (x86)\Arduino\libraries\</code> (Windows x64)<br>
<code>C:\Program Files\Arduino\libraries\</code> (Windows x86)</li>
<li>Подключить Ардуино к компьютеру</li>
<li>Запустить файл прошивки (который имеет расширение .ino)</li>
<li>Настроить IDE (COM порт, модель Arduino, как в статье выше)</li>
<li>Настроить что нужно по проекту</li>
<li>Нажать загрузить</li>
<li>Пользоваться</li>
</ul>
<h2><a id="user-content-настройки-в-коде" class="anchor" aria-hidden="true" href="#настройки-в-коде"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Настройки в коде</h2>
<pre><code>CURRENT_LIMIT 2000  // лимит по току в миллиамперах, автоматически управляет яркостью (пожалей свой блок питания!) 0 - выключить лимит
AUTOPLAY_TIME 30    // время между сменой режимов в секундах

NUM_LEDS 14         // количсетво светодиодов в одном отрезке ленты
NUM_STRIPS 4        // количество отрезков ленты (в параллели)
LED_PIN 6           // пин ленты
BTN_PIN 2           // пин кнопки/сенсора
BRIGHTNESS 250      // начальная яркость
FIRE_PALETTE 0      // разные типы огня (0 - 3). Попробуй их все! =)
</code></pre>
<p><a id="user-content-chapter-5"></a></p>
<h2><a id="user-content-faq" class="anchor" aria-hidden="true" href="#faq"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>FAQ</h2>
<h3><a id="user-content-основные-вопросы" class="anchor" aria-hidden="true" href="#основные-вопросы"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Основные вопросы</h3>
<p>В: Как скачать с этого грёбаного сайта?<br>
О: На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка <strong>Clone or download</strong>, вот её жми, там будет <strong>Download ZIP</strong></p>
<p>В: Скачался какой то файл .zip, куда его теперь?<br>
О: Это архив. Можно открыть стандартными средствами Windows, но думаю у всех на компьютере установлен WinRAR, архив нужно правой кнопкой и извлечь.</p>
<p>В: Я совсем новичок! Что мне делать с Ардуиной, где взять все программы?<br>
О: Читай и смотри видос <a href="http://alexgyver.ru/arduino-first/" rel="nofollow">http://alexgyver.ru/arduino-first/</a></p>
<p>В: Вылетает ошибка загрузки / компиляции!
О: Читай тут: <a href="https://alexgyver.ru/arduino-first/#step-5" rel="nofollow">https://alexgyver.ru/arduino-first/#step-5</a></p>
<p>В: Сколько стоит?<br>
О: Ничего не продаю.</p>
<h3><a id="user-content-вопросы-по-этому-проекту" class="anchor" aria-hidden="true" href="#вопросы-по-этому-проекту"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Вопросы по этому проекту</h3>
<p><a id="user-content-chapter-6"></a></p>
